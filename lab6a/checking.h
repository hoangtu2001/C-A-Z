class CheckingAccount: public Account
{
public:
    
    CheckingAccount(double initalBalance, double fee) : Account(initalBalance)
    {
        if(initalBalance<0) throw std::invalid_argument("The initial balance should be greater than 0 !\n");
        else currentBalance = initalBalance;

        feeCharged = fee;

    }
    void credit(double balance)
    {
       currentBalance = currentBalance+ (balance-feeCharged);
    }
    void debit(double balance)
    {
       if(balance>currentBalance) throw std::out_of_range("The debit balance need could not exceed the current balance! \n");
       else currentBalance = currentBalance - (balance+feeCharged);
    }
private:
    double feeCharged;
};