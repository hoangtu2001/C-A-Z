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

void randTest(int[], const int, const int);
void randomTest(int[], const int, const int);
int randomRange(const int, const int);
int randRange(const int, const int);
void test(int[], const int, const int, int (&)(const int, const int));
void printTestResult(const int[], const int, const int);

int main(int argc, char const *argv[])
{
    const int TEST_QTY = 600000;
    const int FACE_QTY = 6 ;
    int rollCounts[FACE_QTY]  ;
    randTest(rollCounts, TEST_QTY, FACE_QTY);
    randomTest(rollCounts, TEST_QTY, FACE_QTY);

    return 0;
}
void randTest(int counts[], const int size, const int testQty)
{
    std::cout<< "Testing "<< testQty << "rolls using the random function\n\n";
    test(counts, size, testQty, randomRange);
    printTestResult(counts, size, testQty);
}

void randomTest(int counts[], const int size, const int testQty)
{
    std::cout<< "Testing "<< testQty << "rolls using the random function\n\n";
    test(counts, size, testQty, randomRange);
    printTestResult(counts, size, testQty);
}
int randomRange(const int start, const int end)
{
    static std::random_device rd;
    static std::default_random_engine rndEng(rd());
    static std::uniform_int_distribution<int> uniformDist(start, end);

    return uniformDist(rndEng);
}

int randRange(const int start, const int end)
{
    return rand() % (end -start+1) + start;
}
void test(int counts[], const int size, const int testQty, int (&rnd)(const int, const int))
{
    for(size_t i =0 ; i<testQty; i++)
    {
        ++counts[rnd(0, size -1)];
    }
}
void printTestResult(const int counts[], const int size, const int testQty)
{
    std::cout<< std::setw(10)<< "Face" << "Percentage of rolls\n";
    for(size_t i  = 0; i<size; ++i)
    {
        std::cout<<std::setw(10) << i+1<<static_cast<double>(counts[i] *100 /testQty)<<std::endl;
    }
}
