#include <initializer_list>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "ex7-43.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::vector;


int main(int argc, char *argv[])
{
    // ex. 7.1 pg 335
    /*
     *Sales_data total;
     *if (cin >> total.bookNo >> total.units_sold >> total.price)
     *{
     *    total.revenue = total.units_sold * total.price;
     *    Sales_data sale;
     *    while(cin >> sale.bookNo >> sale.units_sold >> sale.price)
     *    {
     *        sale.revenue = sale.units_sold * sale.price;
     *        if (sale.bookNo == total.bookNo)
     *        {
     *            total.revenue += sale.units_sold * sale.price;
     *            total.units_sold += sale.units_sold;
     *        }
     *        else
     *        {
     *            double avgPrice = total.revenue / total.units_sold;
     *            cout << "Book: " << total.bookNo << " " 
     *                 << "Units sold: " << total.units_sold << " "
     *                 << "Average price: " << avgPrice << endl;
     *            total.bookNo = sale.bookNo;
     *            //total.price = sale.price;
     *            total.revenue = sale.revenue;
     *            total.units_sold = sale.units_sold;
     *        }
     *    }
     *    double avgPrice = total.revenue / total.units_sold;
     *    cout << "Book: " << total.bookNo << " " 
     *         << "Units sold: " << total.units_sold << " "
     *         << "Average price: " << avgPrice << endl;
     *}
     */

    // ex. 7.3 pg 340
/*
 *    Sales_data total;
 *    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
 *    {
 *        Sales_data trans;
 *        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
 *        {
 *            if (total.isbn() == trans.isbn())
 *            {
 *                total.combine(trans);
 *            }
 *            else
 *            {
 *                cout << "ISBN: " << total.isbn()
 *                     << " SOLD: " << total.units_sold
 *                     << " AVERAGE $: " << total.avg_price() << endl;
 *
 *                total.bookNo = trans.isbn();
 *                total.units_sold = trans.units_sold;
 *                total.revenue = trans.revenue;
 *            }
 *        }
 *        cout << "ISBN: " << total.isbn()
 *             << " SOLD: " << total.units_sold
 *             << " AVERAGE $: " << total.avg_price() << endl;
 *    }
 */

    if (false)
    {
        // ex. 7.7 pg 342
        Sales_data total;
        if (read(cin, total))
        {
            Sales_data sale;
            while(read(cin, sale))
            {
                if (sale.isbn() == total.isbn())
                {
                    total = add(total, sale);
                }
                else
                {
                    print(cout, total) << endl;
                    total = sale;
                }
            }
            print(cout, total) << endl;
        }
    }

    if (false)
    {
        Person me;
        readPerson(cin, me);
        //printPerson(cout, me);

        Person cunt;
        readPerson(cin, cunt);

        printPerson(printPerson(cout, me) << endl, cunt) << endl;
    }

    if (false)
    {
        // ex. 7.11 pg 347
        cout << "Sales_data()" << endl;
        Sales_data def;
        print(cout, def) << endl;

        cout << "\nSales_data(string n)" << endl;
        Sales_data sdStr("balls");
        print(cout, sdStr) << endl;

        cout << "\nSales_data(string, unsigned, double)" << endl;
        Sales_data sdAll("Stank dick", 7, 4.34);
        print(cout, sdAll) << endl;

        cout << "\nSales_data(istream)" << endl;
        Sales_data sdInput(cin);
        print(cout, sdInput) << endl;
    }

    if (false)
    {
        // ex. 7.13 pg 347
        Sales_data total(cin);
        if (cin) // if cin is in a valid state from Sales_data constructor
        {
            //Sales_data sale(cin);
            while (cin)
            {
                Sales_data sale(cin);
                if (sale.isbn() == total.isbn())
                {
                    total.combine(sale);
                }
                else
                {
                    print(cout, total) << endl;
                    total = sale;
                }
            }
        }
    }

    if (false)
    {
        Person me("Mason", "Old Romney Rd");
        printPerson(cout, me) << endl;

        Person goblin("Garungar", "the cave");
        printPerson(cout, goblin) << endl;

        Person taint("taint", "grundle");
        printPerson(cout, taint) << endl;

        //Person you(cin);
        //printPerson(cout, you) << endl;

        me.changeName("Stank_Dick");
        printPerson(cout, me) << endl;

        const Person oldBitch("LouAnn", "Butterville");
        printPerson(cout, oldBitch) << endl;
        //oldBitch.changeName("Gretzel"); // illegal; can only access const functions
        oldBitch.getName(); // okay
    }

    if (false)
    {
        Screen myScreen(5, 5, 'X');
        myScreen.move(4, 0).set('#').display(cout);
        cout << "\n";
        myScreen.display(cout);
        cout << "\n";
    }

    if (false)
    {
        // ex. 7.41 pg 379
        cout << "sd1:" << endl;
        Sales_data sd1;
        // default initialized, delegated to 3 variable constructor
        // Expected ouput:
        //      Sales_data(const std::string &s, unsigned n, double p)
        //      Sales_data()
        cout << endl;

        cout << "sd2:" << endl;
        Sales_data sd2("ass");
        //      Sales_data(const std::string &s, unsigned n, double p)
        //      Sales_data(const std::string &s)
        cout << endl;

        cout << "sd3:" << endl;
        Sales_data sd3("butts", 4);
        //      Sales_data(const std::string &s, unsigned n, double p)
        //      Sales_data(const std::string &s, unsigned n)
        cout << endl;

        cout << "sd4:" << endl;
        Sales_data sd4("dink", 6, 4.1);
        //      Sales_data(const std::string &s, unsigned n, double p)
        cout << endl;

        cout << "sd5:" << endl;
        Sales_data sd5(cin);
        //      Sales_data(const std::string &s, unsigned n, double p)
        //      Sales_data()
        //      Sales_data(std::istream &is)
        cout << endl;
    }

    C balls;
    vector<C> vec(10);
    string null_isbn("9-99");
    Sales_data item1(null_isbn);
    Sales_data item2("9-999");

    Sales_data i;
    string s;

    // ex. 7.49 pg 385
    // i.combine(s);

    // Sales_data &combine(Sales_data);
    //      Parameter is pass by value, temp Sales_data is
    //      implicitly created from the string s
    //      data members of temp Sales_data are default initialized
    //      units_sold and revenue will both be 0
    //      returns a reference to i

    // Sales_data &combine(Sales_data&);
    //      Parameter is passed by reference

    // Sales_data &combine(const Sales_data&) const;
    //      Parameter is passed by reference
    //      Parameter and object that was called on are const
    //      so members cannot be changed


    return EXIT_SUCCESS;
}
