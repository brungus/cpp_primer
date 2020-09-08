#include <iostream>
#include "Person.h"

//Person::Person(std::istream &is)
//{
    //readPerson(is, *this);
//}

void Person::changeName(const std::string &newName)
{
    name = newName;
}

std::istream &readPerson(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}
std::ostream &printPerson(std::ostream &os, const Person &person)
{
    os << person.getName() << " lives at " << person.getAddress();
    return os;
}
