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

int gcd(int, int);

int main(int argc, char const *argv[])
{
    int n = 1 , m = 1;
    
    while(n != 0 && m != 0)
    {
        std::cout<<"Enter two integers: ";
        std::cin>>n>>m;
        std::cout <<"The greatest common divisor of "<<n<<" and "<<m<<" is "<<gcd(n, m)<<std::endl;
    }
    
    return 0;
}
int gcd(int n, int m)
{
    int temp = 0;
    if(m > n) std::swap(m, n);
    for(int i = 1; i<=m; i++)
    {
        if(n % i == 0 && m % i == 0)
        {
            temp = i;
        }
    }
    if ( m == 0 || n == 0)
    {
        temp = std::abs(m-n);
    }
    return temp;
}


                      