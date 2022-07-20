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
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <climits>
#define WINDOWS false

using namespace std;


int main()
{
    std::string items[8][8];
    for(int i = 0; i< 8; i++)
        for (int j = 0; j<8; j++)
            {
                items[i][j] = "  D";
            }
    std::cout<<items[0][0]<<"\n";
    return 0;
}

