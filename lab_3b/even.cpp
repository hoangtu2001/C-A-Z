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

bool is_even(int);
int main(int argc, char const *argv[])
{
    int n;
    std::cout <<"Enter an integer: ";
    std::cin >>n;
    if(is_even(n))
        std::cout<<n<<" is an even integer"<<std::endl;
    else
        std::cout<<n<<" is an odd integer "<<std::endl;
 
    return 0;
}

bool is_even(int n)
{
    if((n & 1) == 0) return true;
    else return false;
}

                      