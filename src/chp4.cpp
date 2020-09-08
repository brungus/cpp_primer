#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int get_value();
void eatAss()
{}

struct myClass
{
    int arr[3] = {1, 2, 3};
};

void printArray(void *p, size_t size)
{
    auto np = static_cast<int*>(p);
    for (size_t i = 0; i != size; ++i)
    {
        cout << *(np + i) << " ";
    }
    cout << endl;
}

int main()
{

    // (* ( vec.begin() ) )
    // function call, dereference
    // value at address returned by vec.begin()

    // ( ( * ( vec.begin() ) ) + 1 )
    // function call, dereference, addition
    // adds 1 to the value at address returned by vec.begin()

    if (false)
    {
        // ex. 4.4 pg 197

        int x;
        //        16       +    75    +     0           = 91;
        //x = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);
        x = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;

        cout << x << endl;
    }

    if (false)
    {
        // ex. 4.5 pg 197
        int x;
        x = -30 * 3 + 21 / 5; // -90 + 4 = -86
        cout << x << endl;
        x = -30 + 3 * 21 / 5; // -30 + 12 = -18
        cout << x << endl;
        x = 30 / 3 * 21 % 5; // 210 % 5 = 0
        cout << x << endl;
        x = -30 / 3 * 21 % 4; // -210 % 4 = -2
        cout << x << endl;
    }
    
    if (false)
    {
        // ex. 4.6 pg 197
        int x = 4;
        if (x % 2 == 0)
            cout << x << " is even" << endl;
        else
            cout << x << " is odd" << endl;
    }

    if (false)
    {
        //ex. 4.7 pg 197
        unsigned int x = 0xFFFFFFFF;
        cout << x << endl;
        x += 1;
        cout << x << endl;

        char y = 127;
        y += 1;
        int iy = y;
        cout << iy << endl;

        short z = 32767;
        z += 1;
        cout << z << endl;
    }

    if (false)
    {
        // ex. 4.10 pg 201
        int x;
        while (cin >> x && x != 42)
            cout << x << " is not equal to 42." << endl;
        cout << "You entered 42. Good job." << endl;
    }

    if (false)
    {
        //ex. 4.11 pg 201
        int a = 4, b = 3, c = 2, d = 1;
        if (a > b && b > c && c > d)
            cout << "Hooray!" << endl;
        else
            cout << "Noray!" << endl;
    }


    //int i;
    //while ((i = get_value()) != 42)
        //cout << i << " is not equal to 42" << endl;

    //int x = 2;
    //x <<= 1;
    //cout << x << endl;
    //x <<= 1;
    //cout << x << endl;
    //x <<= 2;
    //cout << x << endl;

    //cout << (4 | 12) << endl;
    //cout << (17 & 12) << endl;
    //cout << (17 | 12) << endl;
    //cout << (30 | 17) << endl;

    //unsigned y = 0;
    //cout << ~y << endl;

    if (false)
    {
        // ex. 4.13 pg 205
        int i;
        double d;

        //d = i = 3.5; // i = 3, d = 3.0
        cout << "d: " << d << " i: " << i << endl;
        i = d = 3.5; // d = 3.5, i = 3
        cout << "d: " << d << " i: " << i << endl;
    }
    
    // ex. 4.16 pg 205
    // if ((p = getPtr()) != 0)
    // if (i == 1024)

    if (false)
    {
        // ex. 4.21 pg 211
        vector<int> vec;
        for (int i = 0; i < 10; ++i)
            vec.push_back(i);

        for (auto &i : vec)
        {
            i = (i % 2 != 0) ? i * 2 : i;
            //(i % 2 != 0) ? i *= 2 : i = i;
        }

        for (auto i : vec)
            cout << i << endl;
    }

    if (false)
    {
        // ex 4.22 pg 211
        int i = 56;
        string grade = (i > 90) ? "high pass"
            : (i > 75) ? "medium pass"
            : (i > 60) ? "low pass" : "fail";
        cout << grade << endl;

        i = 56;
        if (i > 90)
            grade = "high pass";
        else if (i > 75)
            grade = "medium pass";
        else
            grade = (i > 60) ? "low pass" : "fail";
        cout << grade << endl;
    }

    if (false)
    {
        // ex 4.23 pg 211
        string s = "words";
        string s1 = "carrot";
        //string pl = ((s + s[s.size() - 1]) == 's') ? "" : "s";
        string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");
        string pl1 = s1 + ((s1[s1.size() - 1] == 's') ? "" : "s");
        cout << pl << endl;
        cout << pl1 << endl;
    }

    if (false)
    {
        // ex. 4.28 pg 218

        cout << "bool: " << sizeof (bool) << " bytes" << endl;
        cout << "char: " << sizeof (char) << " bytes" << endl;
        cout << "wchar_t: " << sizeof (wchar_t) << " bytes" << endl;
        cout << "char16_t: " << sizeof (char16_t) << " bytes" << endl;
        cout << "char32_t: " << sizeof (char32_t) << " bytes" << endl;
        cout << "short: " << sizeof (char) << " bytes" << endl;
        cout << "int: " << sizeof (int) << " bytes" << endl;
        cout << "long: " << sizeof (long) << " bytes" << endl;
        cout << "long long: " << sizeof (long long) << " bytes" << endl;
        cout << "float: " << sizeof (float) << " bytes" << endl;
        cout << "double: " << sizeof (double) << " bytes" << endl;
        cout << "long double: " << sizeof (long double) << " bytes" << endl;
        cout << endl;
        cout << "bool*: " << sizeof (bool*) << " bytes" << endl;
        cout << "char*: " << sizeof (char*) << " bytes" << endl;
        cout << "wchar_t*: " << sizeof (wchar_t*) << " bytes" << endl;
        cout << "char16_t*: " << sizeof (char16_t*) << " bytes" << endl;
        cout << "char32_t*: " << sizeof (char32_t*) << " bytes" << endl;
        cout << "short*: " << sizeof (char*) << " bytes" << endl;
        cout << "int*: " << sizeof (int*) << " bytes" << endl;
        cout << "long*: " << sizeof (long*) << " bytes" << endl;
        cout << "long long*: " << sizeof (long long*) << " bytes" << endl;
        cout << "float*: " << sizeof (float*) << " bytes" << endl;
        cout << "double*: " << sizeof (double*) << " bytes" << endl;
        cout << "long double*: " << sizeof (long double*) << " bytes" << endl;
    }

    if (false)
    {
        // ex. 4.29 pg 218
        int x[10];
        //int *p = x; // equivalent to &x[0]

        // 10, x is not converted to pointer to first element?
        // x is 10 * 4 bytes
        // *x is 4 bytes
        cout << sizeof(x) / sizeof(*x) << endl; 

        //cout << sizeof(p) / sizeof(*p) << endl; // 8 / 4
        // p is just a pointer to int, all pointers are 8 bytes
        // ints a 4 bytes
    }

    if (false)
    {
        // ex. 4.30 pg 218

        // addition operator has lower precedence than sizeof
        //(sizeof x) + y;
        cout << sizeof 1 + 69 << endl;

        // arrow operator and subscript operate have same precedence, higher than sizeof
        // they both have left associativity so the arrow is evaluated before subscript
        //( sizeof ( (p->mem)[i] ) ); // 4, since we are retreiving an int
        myClass m, *p = &m;
        cout << sizeof ((p->arr)[2]) << endl;

        // is sizeof a less than value of b
        //(sizeof a) < b; boolean result
        unsigned a = 12, b = 5;
        cout << (sizeof a < b) << endl;


        // function call operator has higher precedence
        // return type is used with sizeof operator
        //sizeof (f());
        cout << sizeof get_value() << endl;
        //cout << sizeof eatAss() << endl; // error, void cannot be used with sizeof
    }

    if (false)
    {
        vector<int> ivec;
        for (int i = 0; i < 10; ++i)
            ivec.push_back(i);

        vector<int>::size_type cnt = ivec.size();
        for (vector<int>::size_type ix = 0;
                ix != ivec.size(); ++ix, --cnt)
            ivec[ix] = cnt;

        for (auto i : ivec)
            cout << i << " ";
        cout << endl;

        cnt = ivec.size();
        for (vector<int>::size_type ix = 0;
                ix != ivec.size(); ix++, cnt--)
            ivec[ix] = cnt;

        for (auto i : ivec)
            cout << i << " ";
        cout << endl;

        constexpr int size = 5;
        int ia[size] = {1, 2, 3, 4, 5};
        for (int *ptr = ia, ix = 0;
                ix != size && ptr != ia + size;
                ++ix, ++ptr)
        {
            cout << "stink" << endl;
        }

        // conditional ?: has higher precedence than comma
        // so the conditional up until the second comma is evaluated,
        // then that result is used in the second comma operation where
        // y is decremented.
        // If someValue is non-zero, y is incremented and decremented
        //  and x is only incremented
        // (someValue ? ++x, ++y : --x), --y;
        int someValue = 0, x = 0, y = 0;
        ((someValue ? (++x), (++y) : (--x)), (--y));
        cout << "x: " << x << " y: " << y << endl;
        cout << ((((3 * 4) + 1) - ((3 / 4) * 4)) + 2) << endl;
        cout << 3 * 4 + 1 - 3 / 4 * 4 + 2 << endl;
    }

    if (false)
    {
        // ex. 4.34 pg 222
        // if (fval) // fval converted to bool, if 0 it's false, otherwise it's true

        // dval = fval + ival; // ival converted to float, sum converted to double
        int ival = 1;
        float fval = 4.23;
        double dval;
        dval = fval + ival;
        cout << dval << endl;

        // cval promoted to int, result of ival and cval converted to float
        // dval + ival * cval
    }
    
    if (false)
    {
/*
 *        // ex. 4.35 pg 222
 *        char cval;
 *        int ival;
 *        unsigned int ui;
 *        float fval;
 *        double dval;
 *
 *        cval = 'a' + 3;
 *        // 'a' promoted to int
 *        // sum converted to char
 *
 *        fval = ui - ival * 1.0;
 *        // ival converted to double
 *        // ui converted to double
 *        // ui - product converted to float
 *
 *        dval = ui * fval;
 *        // ui converted to float
 *        // product converted to double
 *
 *        cval = ival + fval + dval;
 *        // ival converted to float
 *        // sum converted to double
 *        // total sum converted to char
 */
    }

    if (false)
    {
        int arr[100] = {};
        arr[4] = 4;

        void *p = &arr;
        cout << static_cast<int*>(p)[4] << endl;

        printArray(arr, 100);
    }

    if (false)
    {
        // ex 4.36 pg 227
        int i = 4;
        double d = 3.2;

        i *= static_cast<int>(d);
        cout << i << endl;
    }

    if (false)
    {
        // ex. 4.37 pg 227
        int i = 0;
        double d = 0;
        const string *ps;
        char c = 'c';
        char *pc = &c;
        void *pv;

        pv = (void*)ps;
        pv = static_cast<void*>(const_cast<string*>(ps));
        cout << pv << endl;

        cout << "c: " << c << endl;
        cout << "c cast to int: " << static_cast<int>(c) << endl;
        //i = *(reinterpret_cast<int*>(pc));
        i = int(*pc);
        i = static_cast<int>(*pc);
        cout << "i: " << i << endl;

        pv = &d;
        pv = static_cast<void*>(&d);

        pc = (char*)pv;
        pc = reinterpret_cast<char*>(pv);

        const char cc = 'c';
        int a = 0;
        a = const_cast<char&>(cc);
    }

    char a = 8, b = 3;
    cout << sizeof (a + b) << endl;

    int i = 10, j = 4;
    i = ++i, ++j;
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;

    ++i = 3;
    cout << "i: " << i << endl;

    (++i, ++j) = 69;
    cout << "j: " << j << endl;
    cout << "i: " << i << endl;
    
    i = j++;
    cout << "j: " << j << endl;
    cout << "i: " << i << endl;

    return 0;
}

int get_value()
{
    int x;
    cin >> x;

    return x;
}
