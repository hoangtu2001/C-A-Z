#include <iostream>

#ifndef TESTER_H
#define TESTER_H
class Tester
{
    public:
        Tester() {std::cout<<"constructed";}
        ~Tester() {std::cout<<"Destructed";}
};

#endif