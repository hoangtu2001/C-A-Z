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

template<typename T>
T sum(T a, T b)
{
    return a+b;
}


//definitions go here
int main(int argc, char const *argv[])
{
    std::cout <<sum<int>(10,20)<<std::endl;

    std::cout <<sum<double>(10.0,20.0)<<std::endl;

    std::cout <<sum<char>('A',3)<<std::endl;
    return 0;
}
