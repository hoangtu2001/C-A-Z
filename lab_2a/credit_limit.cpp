/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: Compute credit customer
// why: lab 2a
// when: 03?16/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
void processAccount(int);
double getDouble(std::string);
int main(int argc, char const *argv[]) 
{
    int acc_num = 0;
    std::cout<<"Welcome to the credit limit system (CLS)\n\n";
    
    while(acc_num!=-1) 
    {
        std::cout<<"Enter account number (-1 to end): ";
        std::cin>>acc_num;
        if(acc_num<0) break;

        processAccount(acc_num);

        
    }
    std::cout<<std::endl;
    std::cout<<"Thanks for using credit limit system\n";
    
    return 0;
}

void processAccount(int acc_num)
{
    double beginning_balance = getDouble("Enter starting balance: ");
    double total_charge = getDouble("Enter total charges: ");
    double total_credit = getDouble("Enter total credit: ");
    double credit_limit = getDouble("Enter credit limit: ");
    double new_balance;
   
    new_balance = beginning_balance+total_charge-total_credit;
    std::cout<<std::fixed<<std::setprecision(2);
    if(acc_num>0) std::cout<<std::left<<std::setw(10)<<"New balance is: "<<new_balance<<std::right<<std::setw(10)<<std::endl;
    else new_balance = 0;
    if (new_balance>credit_limit)
    {
        std::cout<<std::left<<std::setw(10)<<"Acount: "<<acc_num<<std::right<<std::setw(10)<<std::endl;
        std::cout<<std::left<<std::setw(10)<<"Credit limit: "<<credit_limit<<std::right<<std::setw(10)<<std::endl;
        std::cout<<std::left<<std::setw(10)<<"Balance: "<<new_balance<<std::right<<std::setw(10)<<std::endl;
        std::cout<<std::left<<std::setw(10)<<"Credit limit exceeded"<<std::endl;
    }
    std::cout<<std::endl;
}
double getDouble(std::string promt){
    double rtnVal;
    std::cout<<promt ;
    std::cin>>rtnVal;
    return rtnVal;
}
