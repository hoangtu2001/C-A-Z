/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: Craps game
// why: lab 3
// when: 27/3/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>

int player1(void);
int player2(void);
int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));
    std::cout<<"Let's take the first roll"<<std::endl;
    bool limit = true;
    int counter = 1;
    int one = player1();
    int two = player2();
    std::cout<<"Dice 1: "<<one<<std::endl;
    std::cout<<"Dice 2: "<<two<<std::endl;
    int sum = one+two;
    std::cout<<"The Sum of two dice in the first roll: "<<sum<<std::endl;
    if(sum==7 || sum == 11)
    {
        
        std::cout<<"Player wins in the first roll"<<std::endl;
    }
    else if(sum==2||sum==3||sum==12)
    {
        
        std::cout<<"Player loses in the first roll"<<std::endl;
    }
    else
    {
        int point  =sum;
        std::cout<<"Player point: "<<point<<std::endl;
        sum  = 0;
        while(sum != point){
            sum = player1()+player2();
            counter++;
            std::cout<<"The Sum of next two dice: "<<sum<<std::endl;
            if (sum==7){
                std::cout<<"Player loses in the "<<counter<<" rolls"<<std::endl;
                limit = false;
                break;
            }
            
        }
        if(limit) std::cout<<"Player wins in the "<<counter<<" rolls"<<std::endl;
        
    }
    return 0;
}
int player1()
{
    int start = 1;
    int end = 6;
    int random = 0;
    random = start + (rand() % (end-start+1));
    return random;
}
int player2()
{
    int start = 1;
    int end = 6;
    int random = 0;
    random = start + (rand() % (end-start+1));
    return random;
}