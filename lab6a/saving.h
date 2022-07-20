class SavingsAccount: public Account
{
public:
    
    SavingsAccount(double initalBalance, double rate) : Account(initalBalance)
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
};