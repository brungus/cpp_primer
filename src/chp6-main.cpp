#include <initializer_list>
#include <iostream>
#include <string>
#include <chp6.h>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::begin;
using std::end;

int main(int argc, char *argv[])
{
    if (false)
    {
        int x = 1, y = 10;

        swapVals(&x, &y);
        outVals(x, y);

        reset(x);
        outVals(x, y);

        swapValsRef(x, y);
        outVals(x, y);
    }

    int x = 0;
    const int cX = 1;
    
    test(x);
    test(cX);
    test2(x);
    test2(cX);

    int i = 0;
    const int ci = i;
    reset(&i);
    //reset(&ci); // parameter has type const int *, cannot ignore low-level const
    reset(i);
    reset(ci); // error: cannot ignore low-level const

    cout << hasCaptial("Dicks") << endl;

    string s = "ASSBALLS";
    strLower(s);
    cout << s << endl;

    cout << strLower2("BIG DICKS") << endl;

    const int size = 10;
    int arr[size] = {};
    populateArray(begin(arr), end(arr));
    printArr(arr, &arr[size]);

    int (&r)[size] = arr;

   printArrRef(r); 
   printArrRef(arr); 

   //int *matrix[10];    // array of ten pointers
   //int *(matrix)[10];  // equivalent
   //int (*matrix2)[10]; // pointer to array of ten ints

   int ix = 12;
   cout << larger(2, &ix) << endl;

    int a = 2, b = 3049;
    int *pA = &a, *pB = &b;
    cout << "*pA: " << *pA << " *pB: " << *pB << endl;

    swapIntPtrs(pA, pB);

    cout << "*pA: " << *pA << " *pB: " << *pB << endl;

    //int bigArr[100] = {};
    //print2(begin(bigArr), end(bigArr));
    
    // ex. 6.25 pg 290
    //string cat = argv[1];
    //cat += argv[2];
    //cout << cat << endl;
    
    // ex. 6.26 pg 290
    for (int i = 0; i != argc; ++i)
    {
        cout << argv[i] << endl;
    }

    std::initializer_list<int> il = {1, 5, 9};

    cout << "initListSum(il): " <<  initListSum(il) << endl;

    string sr;
    std::initializer_list<string> sil = {"ass", "balls"};
    //for (const std::string &elem : sil)
    for (const auto &elem : sil)
    {
        cout << elem << endl;
    }

    void2();

    int nx = 43;
    cout << "nx: " << nx << endl;

    cout << "`lval(nx) = 69`" << endl;
    lval(nx) = 69;

    cout << "nx: " << nx << endl;

    int iarr[10];
    for (int i = 0; i != 10; ++i)
        get(iarr, i) = i;

    printArrRef(iarr);

    vector<int> ivec{1, 2, 3, 4, 5};
    printVec(ivec, static_cast<vector<int>::size_type>(0));

    cout << factorial(-1) << endl;

    string sArr[10]{"ok", "coo", "sick"};

    string (&rA)[10] = sArr;
    retStrArr(rA)[4] = "dump";

    retStrArr2(sArr)[5] = "nice";

    retStrArr3(sArr)[6] = "swick";

    //retStrArr4(sArr)[7] = "nah";

    for (auto s : sArr)
        cout << s << " ";
    cout << endl;

    cout << "Calling okay(), default argument: ";
    okay();
    cout << "Calling okay(38): ";
    okay(38);

    cout << make_plural(3, "dick") << endl;
    cout << make_plural(1, "success") << endl;
    cout << make_plural(2, "success") << endl;
    cout << make_plural(1, "failure") << endl;
    cout << make_plural(2, "failure") << endl;

    prnt(abs(-38));

    printVecDebug(ivec, static_cast<vector<int>::size_type>(0));

    // ex. 6.48 pg 319
    // The loop gets input and stores it in st until either st
    // is equal to the sought input or cin hits EOF or an error input
    // The assert afterwards checks to see if cin is in a valid state,
    // which it will be if sought was found, otherwise it will be in
    // an invalid state.
    //string st, sought = "dicks";
    //while (cin >> st && st != sought) {}
    //assert(cin);

    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    // ex. 6.52 pg 324
    // void manip(int, int);
    // double dobj;
    //
    // manip('a', 'z');     // rank 3, promotion
    // manip(55.4, dobj);   // rank 4, arithmetic conversion

    // pointer to function that returns void and takes 2 int params
    void (*pf)(int, int);
    pf = &f;

    pf(4, 5);

    vector<retIntTakeIntInt> funcType;
    vector<int (*)(int, int)> funcVec;  // vector of pointers to functions that return
                                        // int and take two ints as parameters
    //funcVec.push_back(t1);
    funcVec.push_back(my_add);
    funcVec.push_back(my_sub);
    funcVec.push_back(my_mul);
    funcVec.push_back(my_div);

    for (auto f : funcVec)
    {
        cout << f(19, 4) << endl;
    }


    return EXIT_SUCCESS;
}
