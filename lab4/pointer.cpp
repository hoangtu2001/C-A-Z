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
    const int ARRAY_SZ = 5;
    int array[ARRAY_SZ] = {1,2,3,4,5};
    int* ptr0 = array;
    


    for(int i = 0 ; i < ARRAY_SZ; ++i)
        std::cout<< *(ptr0+i) << " "; //or *(ptr+i)
    std::cout<<std::endl;
    int a = 20;
    int b = 30;
    int* ptr = &a;
    int* ptr2= &b;
    std::cout<<a<<" "<<ptr<<" "<<*ptr<<std::endl;
    
    std::cout<<abs(ptr - ptr2)<<std::endl; 


    return 0;
}
   