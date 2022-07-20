/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: Simple math operations
// why: lab 1b
// when: 6/3/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>

//globals go here

//prototypes og here

unsigned long long fact(const int );

unsigned long long fib(unsigned int);



//definitions go here
int main(int argc, char const *argv[])
{
    //std::cout <<fact(10)<<std::endl;
    std::cout<<fib(50)<<std::endl;
    return 0;
}

/*unsigned long long fact(const int n )
{
    unsigned long long  prod = 1;
    int i = 1;
    for(;i <n; ++i)
    {
        prod *= i;
    }
    return prod;
}*/

/*unsigned long long fact(const int n )
{
    if(n == 1) return 1;
    return n* fact(n-1);
}

unsigned long long fib(unsigned int n)
{
    if( n==0) return n;
    else if (n==1) return n;
    else return fib(n-1)+fib(n-2);
}*/


