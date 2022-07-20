#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <random>
#include <array>
#include "account.h"
#include "saving.h"
#include "checking.h"
int main(int argc, char const *argv[])
{
    std::string name;
    std::cout<<"Enter your account name: ";
    std::getline(std::cin, name);
    std::cout<<std::endl; 

    // Saving account
    std::cout<<"Saving Account Testing\n";
    SavingsAccount saving(1000, 10);
    saving.setName(name);
    std::cout<<"Saving account's name: "<<saving.getName()<<std::endl;
    std::cout<<"The current balance in this saving account: $"<<saving.getBalance()<<std::endl;
    std::cout<<"Lets add $500 and withdraw $300 from this saving account!\n";
    saving.credit(500);
    saving.debit(300);
    std::cout<<"The current balance in this saving account: $"<<saving.getBalance()<<std::endl;
    std::cout<<"The amount of interest earned by this saving account with 10% :"<<saving.calculateInterest()<<"\n";
    std::cout<<"The total balance in this saving account: "<<saving.getBalance()+saving.calculateInterest()<<std::endl;
    std::cout<<std::endl;


    // Checking account
    std::cout<<"Checking Account Testing\n";
    CheckingAccount checking(1000, 22.5);
    checking.setName(name);
    std::cout<<"Checking account's name: "<<checking.getName()<<std::endl;
    std::cout<<"The current balance in this saving account: $"<<checking.getBalance()<<std::endl;
    std::cout<<"Lets add $500 and withdraw $300 from this checking account!\n";
    checking.credit(500);
    checking.debit(300);
    std::cout<<"The current balance in this checking account: $"<<checking.getBalance()<<std::endl;
    std::cout<<std::endl;
}