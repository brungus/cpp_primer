#include <iostream>
#include <string>

typedef int* point; // synonym for pointer to int
// for typedef it may be more convenient to think of the modifier
// (*) in terms of the type instead of the variable
using point2 = int*;

int ok = 3;
point2 const cpti = &ok;

using c16 = char16_t;

constexpr inline int triple(int i)
{
    return (i * 3);
}

const int g = 3;
constexpr const int *gP = &g;

constexpr int j = 3;
constexpr const int *pJ = &j;

int null = 0, *p = &null;

const double cd = 3.4;
auto nd = cd; // results in a double, not a const double

int main()
{
    // ~~> 2.1.2
    //unsigned u = 10u, u2 = 42;
    //std::cout << u2 - u << std::endl; // 32
    //std::cout << u - u2 << std::endl; // 4294967264

    //int i = 10, i2 = 42;
    //std::cout << i2 - i << std::endl; // 32 signed
    //std::cout << i - i2 << std::endl; // -32 signed

    //std::cout << i - u << std::endl; // 0 unsigned
    //std::cout << u - i << std::endl; // 0 unsigned

    // ~~> 2.1.3
    //std::cout << "big ass dicks so big "
                 //"they can't fit on one line" << std::endl;
    //std::cout << L"\x3435" << std::endl;
    //std::cout << 1024.0f << std::endl;

    //std::cout << "2\t\115\n";

    //int j = 100, sum = 0;
    //for (int j = 0; j != 10; ++j)
        //sum += j;
    //std::cout << j << " " << sum << std::endl;

     //2.3.1
    //int i, &ri = i;
    //i = 5;
    //ri = 10;
    //std::cout << i << " " << ri << std::endl; // 10 10

     //2.3.2
    //int x = 78;
    //int &rX = x;
    //int *pX = &rX;
    //std::cout << "x: " << x << " rX: " << rX << std::endl;
    //std::cout << "pX: " << pX << " &x: " << &x << std::endl;

    //double dval;
    //double *pd = &dval;
    //double *pd2 = pd;
    //std::cout << "pd: " << pd << " pd2: " << pd2 << std::endl;

    //int d = 38;
    //int *pI = 0;
    //int *pD = &d;

    //if (pI)
        //std::cout << "You won't see this.\n";
    //if (pD != nullptr)
    //{
        //std::cout << "The pointer is valid!\n";
    //}

    //double dd = 3.2;
    //double other = 4.3;
    //double *pDd = &dd;
    //std::cout << "other: " << other << " pDd: " << pDd << std::endl;
    //double *pDd2 = pDd;
    //pDd = &other;
    //*pDd = 9.9;
    //std::cout << "other: " << other << " pDd: " << pDd << std::endl;

    //int i1 = 42;
    //int *pI1 = &i1;
    //*pI1 = *pI1 * *pI1;
    //std::cout << *pI1 << std::endl;
    
    //int i = 27;
    //int *pI = &i;
    //int **ppI = &pI;
    //int ***pppI = &ppI;
    //int ****ppppI = &pppI;

    //std::cout << "pI: " << pI << " ppI: " << ppI << std::endl;
    //std::cout << "pppI: " << pppI << " ppppI: " << ppppI << std::endl;
    
    //int i = 45;
    //int *p;
    //int *&r = p;
    //std::cout << "p: " << p << " r: " << r << std::endl;
    //r = &i;
    //*r = 0;

    //const double j = 3.0;
    //const int &rJ = j;
    //std::cout << rJ << std::endl;

    //const float dval = 3;
    //const int &r2 = dval;

    //std::cout << r2 << std::endl;

    int i = 45;
    int *pI = &i;

    const int cI = 3;
    const int *cpI = &cI;

    cpI = & i; // legal
    //pI = &cI; // illegal, cannot assign address of const to plain pointer
    
    // regular pointer
    int *p = &i;        // cannot point to a constant
                        // can change value at i
                        // can change address value

    // pointer to const
    const int *pC = &i; // can point to constant or nonconstant
                        // cannot change value at i
                        // can change address value

    // const pointer
    int *const cp = &i; // must be initialized
                        // cannot point to a constant
                        // can change value at i
                        // will always point to i, it cannot change

    // constant pointer to const
    const int *const cpc = &i;  // must be initialized
                                // can point to constant or nonconstant
                                // cannot change value at i
                                // will always point to i
    

    const int v2 = 0;   // const is top-level
    int v1 = v2;        // when copying, doesn't matter if value is constant
    
    int *p1 = &v1;
    int &r1 = v1;

    int i4 = 3;
    const int *p2 = &v2; // const is low-level;
    const int *const p3 = &i4; // const is low-level

    //r1 = v2; // legal, r1 refers to v1 which is an int, v2 top-level const ignored
    //p1 = p2; // illegal, p2 const is low-level, p1 cannot be converted to const
    //p1 = p3; // illegal, p3 top-level const ignored, but p1 cannot convert to l-l const
    //p2 = p1; // legal, p1 low-level converted to const
    //p2 = p3; // legal, same low-level const, top-level const ignored

    int x1 = 0;
    const int x2 = x1;
    int x3 = x2;

    constexpr int mf = 3;
    constexpr int limit = mf + triple(3);

    //int *pudd = &x1;
    point2 pudd = &x1;
    std::cout << pudd << std::endl;

    return 0;
}



/*
 *            Character and Character String Literals
 *        Prefix      Meaning                         Type
 *        u           Unicode 16 character            char16_t
 *        U           Unicode 32 character            char32_t
 *        L           wide character                  wchar_t
 *        u8          utf-8 (string literals only)    char
 *        
 *            Integer Literals        Floating-Point Literals
 *        Suffix      Minimum Type        Suffix      Type
 *        u or U      unsigned            f or F      float
 *        l or L      long                l or L      long double
 *        ll or LL    long long
 */
