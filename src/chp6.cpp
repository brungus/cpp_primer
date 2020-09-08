#include <iostream>
#include <string>
#include "chp6.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ex. 6.3 pg 272
int fact(int n)
{
    int ret = 1;
    while (n > 1)
        ret *= n--;
    return ret;
}

// ex. 6.4 pg 272
void queryFact()
{
    cout << "Enter a number: ";
    int i;
    cin >> i;
    cout << "The factorial of " << i << " is " << fact(i) << endl;
}


// ex. 6.7 pg 272
int genSeq()
{
    static auto ctr = 0;
    cout << "(" << ctr << ") Calling genSeq()" << endl;
    if (ctr == 0)
    {
        ++ctr; // increment for next call on first run
        return 0;
    }
    
    for (auto i = 0; i != ctr; ++i)
        cout << i << " ";
    cout << endl;
    return ctr++; // return ctr and increment for next call
}

// ex. 6.10 pg 278
void swapVals(int *a, int *b)
{
    cout << "Swapping values by pointer" << endl;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reset(const int &cP)
{
}
void reset(int *ip)
{
    cout << "Resetting value by indirection through pointer" << endl;
    *ip = 0;
}

// ex. 6.11 pg 280
void reset(int &i)
{
    cout << "Resetting value by reference" << endl;
    i = 0;
}

// ex. 6.12 pg 280
void swapValsRef(int &a, int &b)
{
    cout << "Swapping values by reference" << endl;
    int tmp = a;
    a = b;
    b = tmp;
}

void outVals(const int &x, const int &y)
{
    cout << "x: " << x << " y: " << y << endl;
}

void test(const int i)
{}

void test2(int i)
{}

//void test(int i) {} // error: redefines test(const int i)
                    // top-level const is ignored on i

// ex. 6.17 pg 284
bool hasCaptial(const string &s)
{
    for (auto beg = s.begin(); beg != s.end(); ++beg)
    {
        if (isupper(*beg))
            return true;
    }
    return false;
}

void strLower(string &s)
{
    for (decltype(s.begin()) it = s.begin(); it != s.end(); ++it)
    {
        *it = tolower(*it);
    }
}

string strLower2(const string &s)
{
    std::string t;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        t.push_back(tolower(*it));
    }
    return t;
}

void printArr(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << " ";
    cout << endl;
}

void populateArray(int *beg, const int *end)
{
    int i = 0;
    while (beg != end)
    {
        *beg++ = i++;
    }
}

void printArrRef(int (&arr)[10])
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

// ex. 6.21 pg 289
int larger(const int a, const int *b)
{
    if (a > *b)
        return a;
    else
        return *b;
}

void swapIntPtrs(int *(&a), int *(&b))
{
    int *t = a;
    a = b;
    b = t;
}

//void print(const int ia[10])
//void print(const int ia[])
//void print(const int *ia)
void print(const int (&ia)[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

void print2(const int *beg, const int *end)
{
    for (auto it = beg; it != end; ++it)
    {
        cout << *it << endl;
    }
}

// ex. 6.27 pg 293
int initListSum(const std::initializer_list<int> il)
{
    int sum = 0;
    for (auto i : il)
        sum += i;
    return sum;
}

void void1()
{
    cout << "In void 1" << endl;
    return;
}

void void2()
{
    cout << "In void 2" << endl;
    return void1();
}

int &lval(int &x)
{
    return x;
}

// ex. 6.30 pg 300
//bool str_subrange(const string &str1, const string &str2)
//{
    //if (str1.size() == str2.size())
        //return str1 == str2;

    //auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    //for (decltype(size) i = 0; i != size; ++i)
    //{
        //if (str1[i] != str2[i])
            //return false;
    //}
//}

int &get(int *arry, int index)
{
    return arry[index];
}

void printVec(vector<int> vec, vector<int>::size_type i)
{
    if (i != vec.size())
    {
        cout << vec[i] << " ";
        printVec(vec, i + 1);
    }
    else
        cout << endl;
}

int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    return 1;
}

// ex. 6.36 pg 303
string (&retStrArr(string (&sArr)[10]))[10]
{
    return sArr;
}

// ex 6.37 pg 303
sArrTen retStrArr2(sArrTen sArr)
{
    return sArr;
}

auto retStrArr3(string (&sArr)[10]) -> string (&)[10]
{
    return sArr;
}

//string arr[10];
//string (&s)[10] = arr;
//decltype(s00) retStrArr4(decltype(s00) sArr)
//{
    //return sArr;
//}

// ex. 6.38 pg 303
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}

using arrF = int (&)[5];

//int (&arrPtr2(int i))[5]          // 
//auto arrPtr2(int i) -> int (&)[5] // -- All equivalent
arrF arrPtr2(int i)                 //
{
    return (i % 2) ? odd : even;
}

// one version of inspect can change x, while the other cannot
void inspect(int &x){}          // x can be changed, nonconst
void inspect(const int &x){}    // x cannot be changed, x const is low-level
                                // overloading ok!

//void pInspect(int *x)         // equivalent, but x could changed to point elsewhere
void pInspect(int * const x)    // takes a const pointer to int   
{
    int z = 10, *p = &z;
    *x = z;     // okay! it's just the pointer itself that is const
    //x = p;    // error: cannot change address to which x points
                // x is a const pointer
    cout << p;
}
//void pInspect(int *x){};  // error: redeclaration of pInspect(int * const)
//                          // top-level const ignored

void pInspect(const int *x)     // takes a pointer to const int
{
    int z = 10, *p = &z;
    //*x = z;   // error: cannot change "const" value to which x points
    x = p;      // okay! the pointer itself is nonconst
}

int *reset1(int *i)
{
    return i;
}

double *reset1(double *d)
{
    return d;
}

void okay(int x)
{
    cout << x << endl;
}

int ff(int a, int b = 0, int c = 0);
//char *init(int ht = 24, int wd, char bckgrnd);

// ex. 6.42 pg 313
string make_plural(size_t ctr, const string &word, 
                                const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void printVecDebug(vector<int> vec, vector<int>::size_type i)
{
    #ifndef NDEBUG
    cout << "-DEBUG- Size: " << i << endl;
    #endif

    if (i != vec.size())
    {
        cout << vec[i] << " ";
        printVec(vec, i + 1);
    }
    else
        cout << endl;
}

// ex. 6.51 pg 321
void f()
{
    cout << "f()" << endl;
}
void f(int)
{
    cout << "f(int)" << endl;
}
void f(int, int)
{
    cout << "f(int, int)" << endl;
}
void f(double, double)
{
    cout << "f(double, double)" << endl;
}

// ex. 6.50 pg 321
// f(2.56, 42)
// Viable: f(int, int) f(double, double)
// Best Match: Illegal call, it is ambiguous because both parameter can be 
//              converted to call a different function

// f(42)
// Viable: f(int) f(double, double)
// Best: f(int), no conversion needed

// f(42, 0)
// Viable: f(int, int) f(double, double)
// Best: f(int, int), no conversion needed

// f(2.56, 3.14)
// Viable: f(int, int) f(double, double)
// Best: f(double, double), no conversion needed

//void calc(int&, int&){}
//void calc(const int &a, const int &b){}

//void calc(char *, char *){}
//void calc(const char *, const char *){}

// illegal, redefinition of calc(char *, char *)
//void calc(char * const, char * const){}

