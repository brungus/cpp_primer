#include <string>
#include <iostream>

class Person;

std::istream &readPerson(std::istream &is, Person &person);
std::ostream &printPerson(std::ostream &os, const Person &person);

class Person
{
    // ex. 7.22 pg 353, hide implementation with access specifiers and friend functions
    friend std::istream &readPerson(std::istream &is, Person &person);
    friend std::ostream &printPerson(std::ostream &os, const Person &person);

    public:
        Person() = default;
        Person(const std::string &n) : name(n) {}
        Person(const std::string &n, const std::string &a) :
                name(n), address(a) {}
        //Person(std::istream &is);
        Person(std::istream &is)
        {
            readPerson(is, *this);
        }

        std::string getName() const { return name; }
        std::string getAddress() const { return address; }

        void changeName(const std::string &newName);

    private:
        std::string name = "N/A";
        std::string address = "N/A";
};

