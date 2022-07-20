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
const size_t array_size = 4;
typedef std::array<int, array_size> intarray;
template<typename T, size_t s>
void printArray(const T array)
{
    for(size_t i = 0; i< s; ++i)
        std::cout<< array.at(i) <<std::endl;
}
int main(int argc, char const *argv[])
{
    const size_t array_size = 4;
    //const int array_size = 4;
    //int array[] = {5,6,7,8,9};
    //std::array<int, array_size> array = {5,6,7,8};
    //printArray< const std::array<int, array_size>&, array_size>(array);


    std::string s = "this is a string ";
    std::cout <<s<<std::endl;
    std::sort(s.begin(), s.end());
    std::cout <<s<<std::endl;
    if(std::binary_search(s.begin(), s.end(), 'r'))
        std::cout<<"r exists\n";

    intarray array = {5,6,7,8};
    std::sort(array.begin(), array.end()); //sort function of array
    for(const int v : array)
    std::cout<< v <<std::endl;

    if(std::binary_search(array.begin(), array.end(), 10))
        std::cout<<"7 exists\n";
    return 0;
}
    