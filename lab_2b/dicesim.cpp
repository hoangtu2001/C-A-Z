/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what:  test random function and random header generator
// why: lab 3a
// when: 03/22/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>

int randTest(int, int);
int randomTest(void);

int main(int argc, char const *argv[])
{
    int number;
    double num1 = 0, num2 = 0, num3 = 0, num4 =0, num5 = 0, num6 = 0;
    srand(static_cast<unsigned int>(time(NULL)));
    for (int j = 1; j<=600000; j++)
    {
        number = randTest(1,6);
        if (number == 1) num1++ ;
        else if (number == 3) num3++;
        else if (number == 4) num4++;
        else if (number == 2) num2++;
        else if (number == 5) num5++;
        else num6++;
        
        number = 0;
    }
    double sum = num1+num2+num3+num4+num5+num6;
    std::cout<<"rand's Simulation (600000 rolls) "<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"1 "<<(num1*100)/sum<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"2 "<<(num2*100)/sum<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"3 "<<(num3*100)/sum<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"4 "<<(num4*100)/sum<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"5 "<<(num5*100)/sum<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"6 "<<(num6*100)/sum<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::end;
    num1 = 0, num2 = 0, num3 = 0, num4 =0, num5 = 0, num6 = 0;

    std::cout<<"Random Header's Simulation (600000 rolls)"<<std::endl;

    

    for (int i=1; i<= 600000; i++)
    {
        int val =  randomTest();;
        if (val == 1) num1++ ;
        else if (val == 3) num3++;
        else if (val == 4) num4++;
        else if (val == 2) num2++;
        else if (val == 5) num5++;
        else num6++;
        
        val = 0;
    }
    double sum1 = num1+num2+num3+num4+num5+num6;
    std::cout<<"rand's Simulation (600000 rolls) "<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"1 "<<(num1*100)/sum1<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"2 "<<(num2*100)/sum1<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"3 "<<(num3*100)/sum1<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"4 "<<(num4*100)/sum1<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"5 "<<(num5*100)/sum1<<std::right<<std::setw(10)<<std::endl;
    std::cout<<std::left<<std::setw(10)<<"6 "<<(num6*100)/sum1<<std::right<<std::setw(10)<<std::endl;
    return 0;
}
int randTest(int start, int end)
{
    int random = 0;
    random = start + (rand() % (end-start+1));
    return random;
}

int randomTest(void)
{
    int val;
    double num1 = 0, num2 = 0, num3 = 0, num4 =0, num5 = 0, num6 = 0;
    std::random_device engn;
    std::uniform_int_distribution<size_t> dist(1, 6);
    val =  dist(engn);
    return val;
}
