#include <iostream>
#include <string>
#include "Sales_data.h"


int main()
{
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.price)
    {
        total.revenue = total.units_sold * total.price;
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.units_sold >> trans.price)
        {
            if (trans.bookNo == total.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.units_sold * trans.price;
            }
            else
            {
                std::cout << total.bookNo << " ";
                std::cout << total.units_sold << " ";
                std::cout << total.revenue << " ";
                // average price per unit sold
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;

                // copy current non-matching data to total
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.units_sold * trans.price;
            }
        }
        std::cout << total.bookNo << " ";
        std::cout << total.units_sold << " ";
        std::cout << total.revenue << " ";
        // average price per unit sold
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
    }


    //Sales_data data1, data2;
    //double price = 0.0;

    //std::cin >> data1.bookNo >> data1.units_sold >> price;
    //data1.revenue = data1.units_sold * price;

    //std::cin >> data2.bookNo >> data2.units_sold >> price;
    //data2.revenue = data2.units_sold * price;

    //if (data1.bookNo == data2.bookNo)
    //{
        //unsigned totalCnt = data1.units_sold + data2.units_sold;
        //double totalRevenue = data1.revenue + data2.revenue;

        //std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

        //if (totalCnt != 0)
        //{
            //std::cout << totalRevenue / totalCnt << std::endl;
        //}
        //else
        //{
            //std::cout << "(no sales)" << std::endl;
        //}
    //}
    //else
    //{
        //std::cerr << "ISBNs do not match." << std::endl;
        //return -1;
    //}

    return 0;
}

