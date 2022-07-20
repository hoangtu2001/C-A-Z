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
int sum(int = 10, int = 20); //formal parameters

int diff(int, int);
int diff(int);
int diff();

//definitions go here
int main(int argc, char const *argv[])
{
    int x = 10; //argument
    int y = 20;
    std::cout<<sum(1,3)<<std::endl;
    std::cout<<diff()<<std::endl;
    std::cout<<diff(x)<<std::endl;  // actual parameters
    std::cout<<diff(x, y)<<std::endl;
 
    return 0;
}
int sum(int a, int b)
{
    return a+b;
}
int diff(int a, int b)
{
    return a-b;
}
int diff(int b)
{
    diff(10, b);
}
int diff()
{
    diff(10, 20);
}