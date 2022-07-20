/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what:  determine the py truples and counting them
// why: lab 2b
// when: 03/20/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>

void swap(double& , double& );
void swap(int& , int& );
void swap(std::string& , std::string& );


int main(int argc, char const *argv[])
{
    std::random_device rd;
    std::mt19937_64 rndEng(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    srand(static_cast<unsigned int>(time(NULL)));
    for(size_t i = 0; i<=2;++i)
        std::cout<<rand()<<std::endl;
    rand();
 
    return 0;
}