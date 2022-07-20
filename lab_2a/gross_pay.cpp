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
    float hours = 1;
    float salary;
    float rate;
    const float maximum = 40;
    while(hours>0){
        std::cout<<"Enter hours worked: ";
        std::cin>>hours;
        if(hours<0) break;
        std::cout<<"Enter hourly rate of the worker: ";
        std::cin>>rate;
        if(hours > maximum) 
        {
            salary = maximum*rate;
            float extra = (hours-maximum)/2*rate;
            salary = salary +(hours-maximum)*rate+ extra;
        }
        else salary = hours*rate;
        std::cout<<"Salary is $"<<std::fixed<<std::setprecision(2)<<salary<<std::endl;
        std::cout<<std::endl;

    }
    
 
    return 0;
}