/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what:  Arrays and Pointers
// why: Lab 4a
// when: 3/14/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <array>
void rolling_dice(int);
int random_generator(void);
void print_table(int);

const int size_arr = 11;
const int total = 600000;
int main(int argc, char const *argv[])
{
    
    srand(static_cast<unsigned int>(time(NULL)));
    std::cout<<"Sum\t\tTotal\t\tExpected\tActual"<<std::endl;
    rolling_dice(total);
    return 0;
}
int random_generator()
{
    int random;
    random = 1 + (rand() % (6-1+1));
    return random;
}    
void rolling_dice(int n)
{
    std::array<int,size_arr> myarray = {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
    std::array<float,size_arr> expect = {2.778, 5.446 ,8.333 ,11.111 ,13.889 ,16.667 ,13.889 ,11.111 ,8.333 ,5.446 ,2.778};
    for(int  i = 1; i<=n ; i++)
    {
        int sum = 0;
        sum = random_generator() + random_generator();
        if (sum == 2) myarray[0]++;
        if (sum == 3) myarray[1]++;
        if (sum == 4) myarray[2]++;
        if (sum == 5) myarray[3]++;
        if (sum == 6) myarray[4]++;
        if (sum == 7) myarray[5]++;
        if (sum == 8) myarray[6]++;
        if (sum == 9) myarray[7]++;
        if (sum == 10) myarray[8]++;
        if (sum == 11) myarray[9]++;
        if (sum == 12) myarray[10]++;      
    }
    for(int i = 0; i<=10; i++)
    {
        float percent;
        float number = 0;
        number = myarray.at(i);
        percent = number/6000;
        std::cout<<i+2<<"\t\t"<< myarray.at(i)<<"\t\t"<<expect.at(i)<<"%"<<"\t\t"<<std::fixed<<std::setprecision(3)<<percent<<"%"<<std::endl;
    }
}

