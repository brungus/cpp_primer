#include <iostream>

int main()
{
/*
 *    int i = 0;
 *    int &r = i;
 *
 *    auto a = r; // a is int
 *
 *    const int ci = i;
 *    const int &cr = ci;
 *    auto b = ci;     // b is int, top-level const in ci ignored
 *    auto c = cr;     // c is int, cr is alias for ci whose const is top-level
 *    auto d = &i;     // d is int* (int pointer), & of int is an int*
 *    auto e = &ci;    // e is const int*, & of const object is low-level
 *
 *    const auto f = ci; // ci deduced to int, f is explicitly const so result is const int
 *
 *    auto &g = ci;   // g is const int&, const int reference,
 *                    // reference to auto-deduce type does not ignore top-level const,
 *                    // consts are not top-level when we bind reference to initializer
 *
 *    //auto &h = 42;   // error, cannot bind non-const reference to literal
 *
 *    const auto &j = 42; // legal, can bind const reference to literal
 *
 *    // defining multiple variables in same statement
 *    // each initializer must have consistent base types 
 *    // consistent base types: (int int*), (const int const int&), (const int&, const int*)
 *    // reference or pointer is part of declarator, not the base type
 *    auto k = ci, &l = i;    // k is int, top level const of ci ignored,
 *                            // l is int&, no consts
 *
 *    auto &m = ci, *p = &ci; // m is const int &, p is const int *
 *                            // top-level const is not ignored for both
 *    
 *    //auto &n = i, *p2 = &ci;   // error, top-level consts do not match,
 *    //                          // and therefore base types do not match
 *                                // n is int, p2 is const int
 *
 *    std::cout << "a: " << a << std::endl;
 *    a = 42; // a is int, so a set to 42
 *    std::cout << "a: " << a << std::endl;
 *
 *    std::cout << "b: " << b << std::endl;
 *    b = 42; // b is int, so b set to 42
 *    std::cout << "b: " << b << std::endl;
 *
 *    std::cout << "c: " << c << std::endl;
 *    c = 42; // c is int, so c set to 42
 *    std::cout << "c: " << c << std::endl;
 *
 *    std::cout << "d: " << d << std::endl;
 *    //d = 42; // d is int *, error, d can only be assigned an address
 *    d = &i;
 *    std::cout << "d: " << d << std::endl;
 *
 *    std::cout << "e: " << e << std::endl;
 *    //e = 42; // e is const int *, error, e can only be assigned an address
 *    e = &i;
 *    std::cout << "e: " << e << std::endl;
 *
 *    std::cout << "g: " << g << std::endl;
 *    //g = 42; // g is const int &, error, g cannot be changed, it refers to const int
 *    std::cout << "g: " << g << std::endl;
 *
 */

    const int i = 42;
    auto j = i;          // j is int, 42
    std::cout << "j: " << j << std::endl;
    const auto &k = i;   // k is const int &, 42
    std::cout << "k: " << k << std::endl;
    auto *p = &i;        // p is const int *; address of i
    std::cout << "p: " << p << std::endl;
    const auto j2 = i;    // j2 is const int, 42
    std::cout << "j2: " << j2 << std::endl;
    const auto &k2 = i;  // k2 is const int &, 42
    std::cout << "k2: " << k2 << std::endl;

    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;
    decltype(cj) y = x;
    std::cout << "ci: " << ci << " y: " << y << std::endl;
    std::cout << "&ci: " << &ci << " &y: " << &y << std::endl;

    //int a = 3, b = 4;
    //decltype(a) c = a;      // type is int
    //decltype((b)) d = a;    // type is int &, int &d = a;
    //++c;
    //++d;
    //std::cout << "a: " << a << std::endl; // 4
    //std::cout << "b: " << b << std::endl; // 4
    //std::cout << "c: " << c << std::endl; // 4
    //std::cout << "d: " << d << std::endl; // 4

    int a = 3, b = 4;
    decltype(a) c = a;      // c is int, 3
    decltype(a = b) d = a;  // d is int &, 3, refers to a
    std::cout << "a: " << a << std::endl; // 3
    std::cout << "b: " << b << std::endl; // 4
    std::cout << "c: " << c << std::endl; // 3
    std::cout << "d: " << d << std::endl; // 3

    decltype(a) dt1 = a;
    auto a1 = a;

    decltype((a)) dt2 = a;
    auto a2 = (a);

    return 0;
}
