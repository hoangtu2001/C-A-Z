#include "person.h"

// Constructor for Person
Person::Person(const Position& pos, char type){
    this -> pos = new Position(pos.x, pos.y);
    this -> type = type;
}

// Get the current position of a Person
Position Person::getPosition() const{
    return *pos;
}

// Gets the type of the person [L, H, A, O, S]
char Person::getType() const {
    return type;
}

/** Equality operator
 * @parameter other the other person object
 * @return true if this object has the same position as the other and false otherwise */
bool Person::operator==(const Person& other) const{
    bool equal_x = pos -> x == other.pos -> x;
    bool equal_y = pos -> y == other.pos -> y;

    return (equal_x && equal_y);
}

/** Inequality operator
 * @parameter other the other person object
 * @return false if this object has the same position as the other and true otherwise */
bool Person::operator!=(const Person& other) const{
    bool equal_x = pos -> x == other.pos -> x;
    bool equal_y = pos -> y == other.pos -> y;
    
    return !(equal_x && equal_y);
}

Person::~Person(){
    delete pos;
}