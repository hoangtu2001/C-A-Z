
#include "account.h"
#include <stdexcept>
#include <sstream>
#include "test.h"

std::string Account::getName()
{
    
    log.push_back("Queried balance, Returned " + name);
    return name;
}

void Account::setName(const std::string& name)
{
    if(name.empty())
        throw std::invalid_argument("Name can not be empty");
    log.push_back("changed name to '" + name + "'");
    this->name = name;
}
double Account::getBalance() 
{
    std::stringstream ss;
    ss<< "Queried balance, Returned " <<balance;
    log.push_back(ss.str());
    return balance; 
}
void Account::setBalance(const double balance) 
{   
    std::stringstream ss;
    if(balance < 0)
        throw std::invalid_argument("Balance can not be negative! ");
    ss<<"changed balance to " << balance;
    log.push_back(ss.str());
    this->balance = balance;
}
std::string Account::getEvens()
{
    std::string out;
    for(const std::string &s: log)
        out+= s+ "\n";
    return out;
}

Account::Account() : log(new std::vector<std::string>)
(
    balance = 0;
}
Account::Account(const std::string& name) : Account(name, 0) { }

Account::Account(const std::string& name, const double balance) : log(new std::vector<std::string>)
{
    setName(name);
    setBalance(balance);
}
void Account::logEvent(const std::string& event)
{
    log->push_back(event);
}

Account::~Account()
{
    delete log;
}