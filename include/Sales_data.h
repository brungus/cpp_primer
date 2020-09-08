#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data;

// helper functions
std::istream &read(std::istream &is, Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::ostream &print(std::ostream &os, const Sales_data &item);

class Sales_data
{
    // helper functions
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);

    public:
        //Sales_data() = default;
        // ex.7.14 pg 347
        Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
        Sales_data(const std::string &s) : bookNo(s) {}
        Sales_data(const std::string &s, unsigned n, double p) :
                    bookNo(s), units_sold(n), revenue(p*n) {}
        Sales_data(std::istream &is);

        std::string isbn() const { return bookNo; }
        Sales_data &combine(const Sales_data &);

    private:
        double avg_price() const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

#endif
