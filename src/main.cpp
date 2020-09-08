#include <initializer_list>
#include <iostream>
#include <string>
#include <cassert>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::begin;
using std::end;


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

    Screen myScreen(4,5);
    myScreen.set('F').display(cout);
    cout << endl;
    myScreen.move(2, 2).set('U').display(cout);
    cout << endl;

    return EXIT_SUCCESS;
}
