#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

int get_value()
{
    return 3;
}

int get_response()
{
    return 0;
}

int get_size()
{
    return 0;
}

int main()
{
    if (false)
    {
        // ex. 5.3 pg 236
        int sum = 0, val = 1;
        while (val <= 10)
            sum += val, ++val;
        cout << "Sum of 1 to 10 inclusive is " << sum << endl;

        sum = 0, val = 1;
        while (val <= 10)
        {
            sum += val;
            ++val;
        }
        cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    }

    if (false)
    {
        // ex. 5.5 pg 241
        int grade = 0;
        cout << "Enter your grade (-1 to quit): ";
        while (cin >> grade && grade != -1)
        {
            string letter_grade;
            if (grade < 60)
                letter_grade = "F";
            else
            {
                if (grade < 70)
                    letter_grade = "D";
                else if (grade < 80)
                    letter_grade = "C";
                else if (grade < 90)
                    letter_grade = "B";
                else if (grade < 100)
                    letter_grade = "A";
                else
                    letter_grade = "A++";

                if (grade < 100)
                {
                    if (grade % 10 < 3)
                        letter_grade += "-";
                    if (grade % 10 > 7)
                        letter_grade += "+";
                }
            }

            cout << "A score of " << grade << " is: " << letter_grade << endl;

            if (grade >= 0)
                cout << "Enter your grade: (-1 to quit): ";
        }
    }

    if (false)
    {
        // ex. 5.6 pg 241
        int grade = 0;
        string letter_grade;
        while (cin >> grade && grade != -1)
        {
            //grade < 60 ? letter_grade = "F"
            //:
            //grade < 70 ? letter_grade = "D"
            //:
            //grade < 80 ? letter_grade = "C"
            //:
            //grade < 90 ? letter_grade = "B"
            //:
            //grade < 100 ? letter_grade = "A"
            //:
            //letter_grade = "A++";

            //grade < 60 ? 
            //letter_grade = "F"
            //: grade < 70 ? 
            //letter_grade = "D"
            //: grade < 80 ? 
            //letter_grade = "C"
            //: grade < 90 ? 
            //letter_grade = "B"
            //: grade < 100 ? 
            //letter_grade = "A"
            //:
            //letter_grade = "A++";

            //grade >= 60 && grade < 100 ? 
            //(
            //grade % 10 < 3 ? 
            //letter_grade += "-"
            //: grade % 10 > 7 ?
            //letter_grade += "+"
            //:
            //letter_grade
            //)
            //:
            //letter_grade;

            letter_grade =  grade < 60 ? "F"
                : grade < 70 ? "D"
                : grade < 80 ? "C"
                : grade < 90 ? "B"
                : grade < 100 ? "A"
                : "A++";

            letter_grade += grade >= 60 && grade < 100 ?
                (
                 grade % 10 < 3 ? 
                 "-"
                 : grade % 10 > 7 ? 
                 "+"
                 : 
                 ""
                )
                : "";

            //grade >= 60 && grade < 100 ? 
            //(
            //grade % 10 < 3 ? 
            //letter_grade += "-"
            //: grade % 10 > 7 ?
            //letter_grade += "+"
            //:
            //letter_grade
            //)
            //:
            //letter_grade;

            cout << "A score of " << grade << " is: " << letter_grade << endl;
        }
    }

/*
 *    if (false)
 *    {
 *        // ex. 5.7 pg 241
 *        int ival1 = 1, ival2 = 2;
 *
 *        if (ival1 != ival2)
 *            ival1 = ival2;
 *        else
 *            ival1 = (ival2 = 0);
 *
 *        int ival = 0;
 *        int minval = 3;
 *        int occurs = 0;
 *        if (ival < minval)
 *        {
 *            minval = ival;
 *            occurs = 1;
 *        }
 *
 *        if (int ival = get_value())
 *        {
 *            cout << "ival = " << ival << endl;
 *            if (!ival)
 *                cout << "ival = 0\n";
 *        }
 *
 *        if (ival == 0)
 *            ival = get_value();
 *    }
 */

/*
 *    if (false)
 *    {
 *        int x = 0;
 *
 *        switch (x)
 *        {
 *            int z; // ok to declare outside of a case
 *            case 1:
 *            //string s;     // illegal, jump bypasses variable initialization
 *            //int i = 0;    // also illegal
 *            int y;          // ok, variable is not initialized
 *            {
 *                string s;   // ok to initialize inside block, it is outside
 *                // scope of other labels
 *            }
 *            break;
 *            case 2:
 *            y = 4;
 *            break;
 *            default:
 *            ;
 *        }
 *    }
 */

    if (false)
    {
        // ex. 5.9 - 5.12 pg 247
        //char c;
        int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
        int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
        int ffCnt = 0, flCnt = 0, fiCnt = 0;
        string line;
        //while (cin >> c)
        while (getline(cin, line))
        {
            ++newlineCnt;
            char prev = ' ';
            for (auto c : line)
            {
                if (c == 'A' || c == 'a')
                    ++aCnt;
                else if (c == 'E' || c == 'e')
                    ++eCnt;
                else if (c == 'I' || c == 'i')
                    ++iCnt;
                else if (c == 'O' || c == 'o')
                    ++oCnt;
                else if (c == 'U' || c == 'u')
                    ++uCnt;
                else if(c == ' ')
                    ++spaceCnt;
                else if (c == '\t')
                    ++tabCnt;

                if (prev == 'f')
                {
                    if (c == 'f')
                        ++ffCnt;
                    else if (c == 'l')
                        ++flCnt;
                    else if (c == 'i')
                        ++fiCnt;
                }
                prev = c;
            }
        }

        cout << endl;
        cout << "Amount of 'a's: " << aCnt << endl;
        cout << "Amount of 'e's: " << eCnt << endl;
        cout << "Amount of 'i's: " << iCnt << endl;
        cout << "Amount of 'o's: " << oCnt << endl;
        cout << "Amount of 'u's: " << uCnt << endl;
        cout << endl;
        cout << "Amount of spaces: " << spaceCnt << endl;
        cout << "Amount of tabs: " << tabCnt << endl;
        cout << "Amount of new lines: " << newlineCnt << endl;
        cout << endl;
        cout << "Amount of 'ff's: " << ffCnt << endl;
        cout << "Amount of 'fl's: " << flCnt << endl;
        cout << "Amount of 'fi's: " << fiCnt << endl;
        cout << endl;
    }

    if (false)
    {
        // ex. 5.13 pg 247-248
        unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
        char ch = 'a';
        switch (ch)
        {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            default:
                ++iouCnt;
        }

        vector<int> ivec;
        unsigned index = 3;
        int ix = 4;
        switch (index)
        {
            case 1:
                //int ix = 4;
                ivec[ix] = index;
                break;
            default:
                ix = ivec.size() - 1;
                ivec[ix] = index;
        }

        unsigned evenCnt = 0, oddCnt = 0;
        int digit = 33 % 10;
        switch (digit)
        {
            case 1: case 3: case 5: case 7: case 9:
                ++oddCnt;
                break;
            case 2: case 4: case 6: case 8: case 0:
                ++evenCnt;
                break;
        }

        //const unsigned ival = 512, jval = 1024, kval = 4096;
        //unsigned bufsize;
        //unsigned swt = 1;

        //switch (swt)
        //{
            //case ival:
                //bufsize = ival * sizeof(int);
                //break;
            //case jval:
                //bufsize = jval * sizeof(int);
                //break;
            //case kval:
                //bufsize = kval * sizeof(int);
                //break;
        //}
    }

    if (false)
    {
        // ex. 5.14 pg 249
        string s, last, most;
        int cnt = 1, mostCnt = 1;;
        while (cin >> s)
        {
            if (s == last)
                ++cnt;
            else
                cnt = 1;

            if (cnt > mostCnt)
            {
                mostCnt = cnt;
                most = s;
            }

            last = s;
        }

        cout << endl;
        if (mostCnt < 2)
            cout << "No word was repeated." << endl;
        else
            cout << "The word '" << most << "' occured the most at " 
                << mostCnt << " times." << endl;
    }

    if (false)
    {
        vector<int> v;
        for (int i = 0; i < 3; ++i)
            v.push_back(i);

        for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
            v.push_back(v[i]);

        for (auto i : v)
            cout << i << " ";
        cout << endl;

        //for (;;)
        //{
        //int i = 0;
        //cin >> i;
        //if (i != 0)
        //break;
        //}

        //for (int i; cin >> i; )
        //v.push_back(i);
        for (auto i : v)
            cout << i << " ";
        cout << endl;

        for (auto i : {3, 4, 5})
        {
            cout << i << " * 2 = " << i * 2 << endl;
        }
    }


    if (false)
    {
        // ex. 5.16 pg 253
        for (int i = 0; i < 10; ++i)
        {}

        // equivalent using a while loop
        int j = 0;
        while (j != 10)
        {
            ++j;
        }


        int i;
        while (cin >> i)
        {}

        // equivalent using a for loop
        for (int i; cin >> i; )
        {}
    }

    if (false)
    {
        // ex. 5.17 pg 253
        //vector<int> vec1{0, 1, 1, 2, 3, 5, 8, 16};
        //vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

        vector<int> vec1, vec2;

        cout << "Enter values for vec1: ";
        for (int i; cin >> i && i != -1; )
            vec1.push_back(i);

        cout << "Enter values for vec2: ";
        for (int i; cin >> i && i != -1; )
            vec2.push_back(i);

        vector<int> *pSmall = &vec1, *pBig = &vec2;
        string smVec = "vec1", lgVec = "vec2";
        if (vec1.size() > vec2.size())
        {
            pBig = &vec1;
            pSmall = &vec2;

            lgVec = "vec1";
            smVec = "vec2";
        }

        bool prefix = true;
        //for (auto itSm = pSmall->begin(), itLg = pBig->begin();
                //itSm != pSmall->end(); ++itSm, ++itLg)
        //{
            //if (*itSm != *itLg)
                //prefix = false;
        //}

        for (decltype(pSmall->size()) i = 0; i != pSmall->size(); ++i)
        {
            if ((*pSmall)[i] != (*pBig)[i])
                prefix = false;
        }

        if (prefix)
            cout << smVec << " is a prefix of " << lgVec << "." << endl;
        else
            cout << smVec << " is NOT a prefix of " << lgVec << "." << endl;
    }

    if (false)
    {
        // ex. 5.18 pg 255
        do
        {
            int v1, v2;
            cout << "Please enter two numbers to sum: ";
            if (cin >> v1 >> v2)
                cout << "Sum is: " << v1 + v2 << endl;
        } while (cin);

        int ival;
        do
        {

        } while ((ival = get_response()));

        int jval;
        do
        {
            jval = get_response();
        } while (jval);
    }

    if (false)
    {
        // ex. 5.19 pg 256
        do
        {
            cout << "Enter two strings: ";
            string a, b;
            cin >> a >> b;
            if (a < b)
                cout << a << " is less than " << b << endl;
            else if (a > b)
                cout << b << " is less than " << a << endl;
            else
                cout << "Those are the same string." << endl;
        } while (cin);
    }

    if (false)
    {
        // ex. 5.20 pg 257 / ex. 5.21 pg 258
        string s, last;
        bool twice = false;
        while (cin >> s && !s.empty())
        {
            if (s[0] != toupper(s[0]))
                continue;
            if (s == last)
            {
                twice = true;
                break;
            }
            last = s;
        }

        if (twice)
            cout << "The word " << last << " occurred twice in succession." << endl;
        else
            cout << "No words were repeated in succession." << endl;
    }

    if (false)
    {
        // ex 5.22 pg 259
        int sz;
        do
        {
            sz = get_size();
        } while (sz <= 0);

        sz = 0;
        while (sz <= 0)
            sz = get_size();

        for (int sz; (sz = get_size() && sz <= 0); )
            ;
    }

    // ex 5.23 - 5.25 pg 264
    //int a, b;
    //cin >> a >> b;
    //if (b == 0)
        //throw runtime_error("Tried to divide by zero (0).");
    //cout << a / b << endl;

    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("Cannot divide by zero.");
                // throw 'raises' an exception
            cout << a / b << endl;
        }
        // runtime_error is an exception class
        // runtime_error err is the exception declaration
        catch (runtime_error err) // catch clause, also known as exception handler
        {
            cout << err.what() << endl;
            cout << "\nWould you like to try again? (y/n): ";
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }

    }

    return 0;
}
