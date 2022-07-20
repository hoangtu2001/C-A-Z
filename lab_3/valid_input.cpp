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
int getValidInt(); // input value v st 0<v <=10


//definitions go here
int main(int argc, char const *argv[])
{
   
    std::cout<<getValidInt();
    return 0;
}
int getvalidInt()
{
    int val;
    std::cout<<"Enter avalue between 1 and 10: "; 
    std::cin>>val;
    if(val<1||val>=10)
    {
        std::cout<<"What are you stupid!!!\n";
        return getValidInt();
    }
    return val;
}



