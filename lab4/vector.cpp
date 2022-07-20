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
#include <array>
#include <vector>
void printIntVector(const std::vector<int>&);

int main(int argc, char const *argv[])
{
    static const int arr[] = {1,2,3,4,5,6,7,8,9};
    std::vector<int> v (arr, arr + (sizeof(arr)) / sizeof(arr[0]) );

    for(size_t i = 10; i<20; i++)
        v.push_back(i);
    printIntVector(v);
    return 0;
}

void printIntVector(const std::vector<int>& vect)
{
    std::cout << "{ ";
    for(int i = 0; i<=vect.size(); ++i)
        std::cout << vect[i] << " ";
    std::cout <<"}"<<std::endl;
}