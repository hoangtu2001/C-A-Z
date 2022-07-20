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
#include <iterator>
#include <memory>

struct widget
{
    widget(int c){std::cout<< "Constructed\n";}
    ~widget(){std::cout<< "Destructed\n";}
    
};

void takewidget(std::unique_ptr<widget>& w)
{

}
int main(int argc, char const *argv[])
{
    
    {
        std::unique_ptr<widget> w  = std::make_unique<widget>(10);
        //widget* w = new widget[10];
        //std::shared_ptr<widget> x = w;
        //delete[] w;
        takewidget(std::move(w));
    }
    std::cin.get();
    return 0;
}



        