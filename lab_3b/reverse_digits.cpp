/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: Functions and an Introduction to Recursion
// why: lab 3b
// when: 10/4/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>

void printReverseDigits (int);

int main(int argc, char const *argv[])
{
   int number = 1;
   while (number!=0)
   {
        std::cout<<"Enter the number between 1 and 9999: ";
        std::cin>>number;
        while(number < 1 || number > 9999)
        {
            std::cout<<"Please enter the number between 1 and 9999: ";
            std::cin>>number;    
        }
        
        std::cout<<"The number with its digit reversed is: ";
        printReverseDigits(number);
   }
    return 0;
}

void printReverseDigits(int n)
{
    if(n < 10)
        std::cout<<n<<std::endl;
    else
    {
        std::cout<<n%10;
        printReverseDigits(n/10);
    }
}
                      