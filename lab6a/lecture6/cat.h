#include "pet.h"

#ifndef CAT_H
#define CAT_H

class Cat : public Pet
{
public:
    Cat(const std::string&); // breed
    Cat(const std::string&, const std::string&); // breed and name
    virtual std::string speak() const;
};

#endif