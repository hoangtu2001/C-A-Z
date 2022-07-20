#include <stdexcept>
#include "pet.h"

Pet::Pet(const std::string& breed, const std::string& name) : Pet(breed, name, "") {} // set breed and name

Pet::Pet(const std::string& type, const std::string& breed, const std::string& name) : type {type}, name {name}, breed {breed} {} // set breed, name and type

std::string Pet::getType() const
{
    return type;
}

void Pet::setType(const std::string& type)
{
    this->type =type;
}

std::string Pet::getName() const{
    return name;
}

void Pet::setName(const std::string& name)
{
    this->name = name;
}

std::string Pet::getBreed() const
{
    return breed;
}

void Pet::setBreed(const std::string& breed)
{
    if (breed.empty()) throw std::invalid_argument("Breed cannot be empty");
    this->breed = breed;
}

void Pet::operator=(const Pet& p)
{
    type = p.type;
    breed = p.breed;
    name = p.name;
}

std::ostream& operator<<(std::ostream& os, const Pet& p)
{
    os << p.getName() << " the " << p.getType() << " is a "
                  << p.getBreed() << " and says " << p.speak();
    return os;
}