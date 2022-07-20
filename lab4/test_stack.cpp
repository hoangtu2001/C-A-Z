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
#include "stack.h"

int main(int argc, char const *argv[])
{
    
    push("top of the stack");
    push("part 2 of the stack");
    push("part 3 of the stack");
    push("part 4 of the stack");
    push("part 8 of the stack");
    push("part 16 of the stack");
    push("part 32 of the stack");
    push("bottom of the stack");

    while(!isEmpty())
        std::cout<<pop() <<std::endl;
    
 
    return 0;
}
    