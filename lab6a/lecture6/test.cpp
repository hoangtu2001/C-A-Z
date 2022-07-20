#include <iostream>
#include <vector>

#include "dog.h"
#include "cat.h"

int main(int argc, char const *argv[])
{
    std::vector<Pet*> pets { new Dog("Shih-poo", "Milo"), new Cat("Calico", "Black") };

    Pet* d1 { new Dog{""} };

    *d1 = *pets[0];
    
    for(Pet* p : pets)
    {
        // << is already overloaded with new definition
        std::cout << *p << std::endl;
    }

    std::cout << *d1 << std::endl;
    return 0;
}