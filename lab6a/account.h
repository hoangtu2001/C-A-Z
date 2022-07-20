// Account class with a constructor that initializes the account name.
#include <string>
class Account
{
protected:
    double currentBalance;
public:

    
   // constructor initializes data member name with parameter accountName
   explicit Account(std::string accountName) : name{accountName}
   { // member initializer
      // empty body
   }
   Account(double initalBalance) 
   { 
       if(initalBalance<0) throw std::invalid_argument("The initial balance should be greater than 0 !\n");
       else currentBalance = initalBalance;
   }
   // function to set the account name
   void setName(std::string accountName)
   {
      name = accountName;
   }
   // function to retrieve the account name
   std::string getName() const
   {
      return name;
   }

   void credit(double balance)
   {
       currentBalance+=balance;
   }
   void debit(double balance)
   {
       if(balance>currentBalance) throw std::out_of_range("The debit balance need could not exceed the current balance! \n");
       else currentBalance-=balance;
   }
   double getBalance()
   {
       return currentBalance;
   }
private: 
    std::string name; // account name data member
};                   // end class Account




