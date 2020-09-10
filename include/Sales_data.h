#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
    // helper functions
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);

    public:
        //Sales_data() = default;
        // ex.7.14 pg 347
        //Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
        // defines the default constructor as well as one that takes a string arg
        // non-delegating constructor
        Sales_data(const std::string &s, unsigned n, double p) :
                    bookNo(s), units_sold(n), revenue(p*n)
        {
            std::cout << "Sales_data(const std::string &s, unsigned n, double p)" << std::endl;
        }

        //default constructor, delegates to above
        Sales_data() : Sales_data("", 0, 0)
        {
            std::cout << "Sales_data()" << std::endl;
        }
        explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0)
        {
            std::cout << "Sales_data(const std::string &s)" << std::endl;
        }
        Sales_data(const std::string &s, unsigned n) :
                                            Sales_data(s, n, 0)
        {
            std::cout << "Sales_data(const std::string &s, unsigned n)" << std::endl;
        }
        Sales_data(std::istream &is) : Sales_data()
        {
            std::cout << "Sales_data(std::istream &is)" << std::endl;
            read(is, *this);
        }
        //Sales_data(std::istream &is = std::cin);

        std::string isbn() const { return bookNo; }
        Sales_data &combine(const Sales_data &);

    private:
        double avg_price() const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

// helper functions
std::istream &read(std::istream &is, Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::ostream &print(std::ostream &os, const Sales_data &item);

#endif
