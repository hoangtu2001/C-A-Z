#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <random>
#include <array>
#include "bucket.h"

int main(int argc, char const *argv[])
{
    Bucket bucket;
    std::cout<<"The number of items at the present: "<<bucket.count()<<std::endl;
    for (int i = 0; i <10; i++)
    {
        bucket.add(i+1);
    }
    bucket.add(11); // resize the array from 10 to 20
    std::cout<<"The number of items at the present: "<<bucket.count()<<std::endl;
    if(bucket.remove(3)) std::cout<<"The number 3 has been removed from the list item!!\n";
    std::cout<<"The number of items at the present: "<<bucket.count()<<std::endl;
    bucket.add(4);
    
    std::cout<<"The frequency of number 4 in this item list is: "<<bucket.getFrequency(4)<<std::endl;
    std::cout<<"The number of items at the present: "<<bucket.count()<<std::endl;
    if(bucket.contains(11)) std::cout<<"Number 11 has been placed on the list!\n";
    else std::cout<<"Number 11 has not been placed on the list!\n";
    bucket.clear();
    std::cout<<"The number of items at the present: "<<bucket.count()<<std::endl;

}