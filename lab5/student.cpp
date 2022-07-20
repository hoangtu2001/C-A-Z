#include "Student.h"

Student::Student()
{
    ++count;
}
Student::~Student()
{
    --count;
}
int Student::getCount()
{
    return count;
}
