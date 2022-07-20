#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
class Account
{
private:
    std::string name;
    double balance;
    std::vector<std::string> log;
    void logEvent(const std::string&);
public:

    Account();
    Account(const std::string&);
    Account(const std::string& , const double) ;
    std::string getName();

    void setName(const std::string&);

    double getBalance();
    void setBalance(double);

    std::string getEvens();
};


#endif