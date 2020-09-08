//#define NDEBUG

#ifndef CHP6_H
#define CHP6_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int fact(int n);

void queryFact();

//int abs(int i);
// ex. 6.5 pg 272, ex. 6.45 pg 316 (inline)
inline int abs(int i)
{
    if (i > 0)
        return i;
    else
        return -i;
}

int genSeq();

void swapVals(int *a, int *b);

void reset(int &i);
void reset(int *ip);
void reset(const int &cP);

void swapValsRef(int &a, int &b);

void outVals(const int &x, const int &y);

void test(const int i);

void test2(int i);

bool hasCaptial(const string &s);

void strLower(string &s);

string strLower2(const string &s);

// ex. 6.18 pg 284
//bool compare(matrix &a, matrix &b);

vector<int>::iterator change_val(int nVal, vector<int>::iterator pos);

double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);

void printArr(const int *beg, const int *end);

void populateArray(int *beg, const int *end);

void printArrRef(int (&arr)[10]);

int larger(const int a, const int *b);

//void swapIntPtrs(int *a, int *b);
void swapIntPtrs(int *(&a), int *(&b));

//void print(const int ia[10]);
void print(const int (&ia)[10]);
void print2(const int *beg, const int *end);

int initListSum(const std::initializer_list<int> il);

void void1();
void void2();

int &lval(int &x);

int &get(int *arry, int index);

//void printVec(vector<int> vec, int i);
void printVec(vector<int> vec, vector<int>::size_type i);

int factorial(int val);

string (&retStrArr(string (&sArr)[10]))[10];

using sArrTen = string (&)[10];
sArrTen retStrArr2(sArrTen sArr);

auto retStrArr3(string (&sArr)[10]) -> string (&)[10];

//string arr00[10];
//string (&s00)[10] = arr00;
//decltype(s00) retStrArr4(decltype(s00) sArr);

void okay(int x = 4);

string make_plural(size_t ctr, const string &word, const string &ending = "s");

// ex. 6.42 pg 316
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

inline void prnt(int x)
{
    cout << x << endl;
}

void printVecDebug(vector<int> vec, vector<int>::size_type i);

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int bruh(int);
using PF = int(*)(int); // PF is an alias for a pointer to a function that
                        // returns int and takes an int

//PF returnsPointerToFunc()
//{
    //PF x = bruh;
    //return x;
//}

// ex. 6.54 pg 328
using iFunc = int (*)(int, int);

int t1(int, int);
typedef decltype(t1) *retIntTakeIntInt; // equivalent to iFunc, get type from an
                                        // already declared function, decltype does
                                        // not automatically conver to pointer so
                                        // the * is needed

inline int my_add(int a, int b)
{
    cout << a << " + " << b << " = ";
    return a + b;
}

inline int my_sub(int a, int b)
{
    cout << a << " - " << b << " = ";
    return a - b;
}

inline int my_mul(int a, int b)
{
    cout << a << " * " << b << " = ";
    return a * b;
}

inline int my_div(int a, int b)
{
    cout << a << " / " << b << " = ";
    return a / b;
}


#endif
