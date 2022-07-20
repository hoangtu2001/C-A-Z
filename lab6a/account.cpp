#include "account.h"


class SavingsAccount: public Account
{
public:
    
    SavingsAccount(double initalBalance, double rate)
    {
        if(initalBalance<0) throw std::invalid_argument("The initial balance should be greater than 0 !\n");
        else currentBalance = initalBalance;

        interestRate = rate;

    }
    double calculateInterest()
    {
        return currentBalance*interestRate;
    }
private:
    double interestRate;
}

class CheckingAccount: public Account
{
public:
    double ;
    CheckingAccount(double initalBalance, double fee)
    {
        if(initalBalance<0) throw std::invalid_argument("The initial balance should be greater than 0 !\n");
        else currentBalance = initalBalance;

        feeCharged = fee;

    }
    void credit(double balance)
    {
       currentBalance+=(balance-feeCharged);
    }
    void debit(double balance)
    {
       if(balance>currentBalance) throw std::out_of_range("The debit balance need could not exceed the current balance! \n");
       else currentBalance-=(balance+feeCharged);
    }
private:
    double feeCharged;
}