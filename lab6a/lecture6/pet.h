#include <string>
#include <iostream>

#ifndef PET_H
#define PET_H

class Pet
{
    friend std::ostream& operator<<(std::ostream&, const Pet&);

private:
    std::string name;
    std::string type;
    std::string breed;

public:
    Pet(const std::string&, const std::string&); // set name nad breed
    Pet(const std::string&, const std::string&, const std::string&); // set type, breed and name

    // when using virtual, you are telling the compiler to run the definition from the derived class
    // if the base class doesn't have the definition
    // when you set the function to 0, you are telling the compiler that it must run from the derived class
    virtual std::string speak() const = 0; 

    void operator=(const Pet&);

    std::string getType() const; // when label const, it will not allows the function to be call if it change the internal state of object
    std::string getName() const;
    std::string getBreed() const;

    void setType(const std::string&);
    void setName(const std::string&);
    void setBreed(const std::string&);
};
#endif