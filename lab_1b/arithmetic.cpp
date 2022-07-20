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

int main(int argc, char const *argv[])
{
    int a,b,c;
    std::cout<<"Input three unique integers:";
    std::cin>>a>>b>>c;
    std::cout<<"Sum is "<<a+b+c<<std::endl;
    std::cout<<"Average is "<<(a+b+c)/3<<std::endl;
    std::cout<<"The product is "<<a*b*c<<std::endl;
    std::cout<<"The sum of their squares is "<<a*a+b*b+c*c<<std::endl;
    std::cout<<"The square of their sum is "<<(a+b+c)*(a+b+c)<<std::endl;
    if (a<b) std::swap(a,b);
    if (b<c) std::swap(b,c);
    std::cout<<"The minimum value is "<<c<<std::endl;
    if (a>b) std::swap(a,b);
    if (b>c) std::swap(b,c);
    std::cout<<"The maximum value is "<<c<<std::endl;
    return 0;
}