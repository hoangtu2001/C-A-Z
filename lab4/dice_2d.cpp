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

const int size_arr = 6;
const int total = 600000;
int main(int argc, char const *argv[])
{
    
    srand(static_cast<unsigned int>(time(NULL)));
    std::cout << std::setw(12);
    std::cout<<1<<std::setw(16)<<2<<std::setw(16)<<3<<std::setw(16)<<4<<std::setw(16)<<5<<std::setw(16)<<6<<std::endl;
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
    std::array<int,size_arr> myarray = {0, 0 ,0 ,0 ,0 ,0};
    std::array<int,size_arr> myarray2 = {0, 0 ,0 ,0 ,0 ,0};
    for(int  i = 1; i<=n ; i++)
    {
        int row = 0, column = 0;
        row = random_generator();
        column = random_generator();
        if (row == 1) myarray[0]++;
        if (row == 2) myarray[1]++;
        if (row == 3) myarray[2]++;
        if (row == 4) myarray[3]++;
        if (row == 5) myarray[4]++;
        if (row == 6) myarray[5]++;
        if (column == 1) myarray2[0]++;
        if (column == 2) myarray2[1]++;
        if (column == 3) myarray2[2]++;
        if (column == 4) myarray2[3]++;
        if (column == 5) myarray2[4]++;
        if (column == 6) myarray2[5]++;   

    }
    for(int i = 0; i<=5; i++)
    {
        std::cout<<i+1;
        for(int j = 0; j<=5; j++)
        {
            std::cout<<"\t"<<myarray2[j]+myarray[i]<<"\t";
        }
        std::cout<<std::endl;
    }
}

