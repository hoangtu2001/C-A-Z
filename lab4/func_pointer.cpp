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
#include "func.h"
int compute(int, int, int ()(int, int));

void func(double, double, void ()(const std::string&));

int add(int a, int b) { return a + b; }
int mult(int a, int b) { return a *b; }
int divide(int a, int b) { return a / b; }

int main()
{
    int a = 20;
    int b = 30;

    func(10, 220, logToFile);

    // the address of the add function is passed into the pointer
    // std::cout << compute(a, b, add) << "\n";

    // std::cout << compute(a, b, mult) << "\n";

    // std::cout << compute(a, b, divide) << "\n";


    return 0;
}

int compute(int x, int y, int (*computer)(int, int))
{
    return computer(x, y);
}

void func(double d1, double d2, void (*logger)(const std::string&))
{
    // this processes data and logs it
    logger("Took in two doubles\n");
}