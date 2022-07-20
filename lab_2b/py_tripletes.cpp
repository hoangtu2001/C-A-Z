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
#include <iomanip>
#include <cmath>
void generateTriplets(int); // input max size 
void printTriplet(int, int, int);
int generateSideB(const int, const int);
int main(int argc, char const *argv[])
{
    std::cout <<std::left <<std::setw(10) << "a"<<std::setw(10)<<"b"<<"c\n";
    // generate and print the triplets - max size 500
    generateTriplets(500);
    return 0;
}
void generateTriplets(const int maxSize)
{
    int a = 1;
    int b = 1;
    double c = 0;
    int counter = 0;
    // loop on side a (from 1 to maxsize-2)
    for( ; a<maxSize-1; ++a)
    {
        // loop on b (from a + 1 tp maxsize -1)
        
        
        if(generateSideB(a, maxSize)==a+1) break;
        ++counter;
    }
    
    std::cout<<"A total of "<<counter<<" triples was found.";
    std::cout<<std::endl;
}
int generateSideB(int a, int maxSize)
{
    int b = 1;
    double c = 0;
    int counter = 0;
    for(b =a+1; b<maxSize; b++)
    {
        ++counter;
        c = sqrt(a*a+b*b);
        if(c>maxSize) break;

        if(floor(c) == c) printTriplet(a,b,c);

            
    }
    
    return b;
}
void printTriplet(int a, int b, int c)
{
    std::cout <<std::left <<std::setw(10) <<a<<std::setw(10)<<b<<c<<std::endl;
   
}
