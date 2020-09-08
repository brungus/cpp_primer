#include <iostream>
#include "Sales_item.h"

/*
 * C++ Primer 5th Edition
 * Chapter 1 notes/scratchpad
 */

int main()
{
    // ~~> 1.2
    std::cout << "Hello, world" << std::endl;

    int x = 4, y = 8;
    std::cout << "4 * 8 = ";
    std::cout << x * y ;
    std::cout << std::endl;

    if (x == y)
        std::cout << "dump";

    // ~~> 1.3

    // "/*"
    // "*/"
    // error
    // " /* "
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    //std::cout /* "*/" */;
    std::cout << /*  "*/" /* "/*"  */ << std::endl;

    // ~~> 1.4.1
    int val = 50, sum = 0;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << "The sum of 50 to 100 inclusive is: " << sum << std::endl;

    val = 10; sum = 0;
    while (val >= 0)
    {
        sum += val;
        --val;
    }
    std::cout << "The sum of 10 to 1 inclusive is: " << sum << std::endl;

    std::cout << "Enter two numbers: ";
    int n1 = 0, n2 = 0;
    //std::cin >> n1 >> n2;
    // first number entered is larger
    int n = n1;
    while (n <= n2)
    {
        std::cout << n << " ";
        ++n;
    }
    // second number entered is larger
    n = n2;
    while (n <= n1)
    {
        std::cout << n << " ";
        ++n;
    }
    std::cout << "\n";

    // ~~> 1.4.2
    sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;
    std::cout << "sum: " << sum << std::endl;

    sum = 0;
    for (int i = 50; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << "50 - 100 sum: " << sum << std::endl;

    std::cout << "Enter two numbers: ";
    n1 = 0, n2 = 0, sum = 0;
    //std::cin >> n1 >> n2;
    for (int i = n1; i <= n2; ++i)
        std::cout << i << " ";
    for (int i = n2; i <= n1; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    val = 0;
    sum = 0;
    while (0)//std::cin >> val)
    {
        sum += val;
    }
    std::cout << "sum: " << sum << std::endl;

    sum = 0;
    val = 0;
    std::cout << "Enter amount of numbers to sum: ";
    int num = 0;
    //std::cin >> num;
    for (int i = 0; i < num; ++i)
    {
        std::cin >> val;
        sum += val;
    }
    std::cout << "sum: " << sum << std::endl;

    // ~~> 1.4.4

    /*
     *int currVal = 0;
     *val = 0;
     *if (std::cin >> currVal) // make sure data is of the right type, int
     *{
     *    int cnt = 1;
     *    while (std::cin >> val)
     *    {
     *        if (val == currVal)
     *        {
     *            ++cnt;
     *        }
     *        else
     *        {
     *            std::cout << "The value " << currVal << " appears " 
     *                      << cnt << " times." << std::endl;
     *            currVal = val;
     *            cnt = 1;
     *        }
     *    }
     *    std::cout << "The value " << currVal << " appears " 
     *              << cnt << " times." << std::endl;
     *}
     */

    std::cout << "Enter two numbers: ";
    n1 = 0, n2 = 0;
    //std::cin >> n1 >> n2;
    if (n2 < n1)
    {
        int t = n1;
        n1 = n2;
        n2 = t;
    }
    for (int i = n1; i <= n2; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    // ~~> 1.5.1
    //Sales_item sale1, sale2;
    //std::cin >> sale1 >> sale2;
    //std::cout << sale1 + sale2 << std::endl;

    //std::cout << std::endl;

    //Sales_item sale, total;
    //while (std::cin >> sale)
    //{
        //std::cout << sale << std::endl;
        //total += sale;
    //}
    //std::cout << "Total: " << total << std::endl;

    // ~~> 1.5.2
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (trans.isbn() == total.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}
