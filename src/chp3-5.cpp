// chapter 3.5 Arrays

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iterator>
#include <cstddef>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;

int main()
{
    if (false)
    {
        // ex. 3.31 pg 167
        constexpr size_t size = 10;
        int arr[size];
        for (size_t i = 0; i < size; ++i)
        {
            arr[i] = i;
            cout << i << ": " << arr[i] << endl;
        }
        // ex. 3.32
        cout << "\narr2:" << endl;
        int arr2[size];
        for (size_t i = 0; i < size; ++i)
        {
            arr2[i] = arr[i];
            cout << i << ": " << arr2[i] << endl;
        }

        vector<int> ivec;
        for (int i = 0; i < 10; ++i)
        {
            ivec.push_back(i);
        }
        vector<int> ivec2 = ivec;

        cout << "\nivec:" << endl;
        int cnt = 0;
        for (auto i : ivec)
        {
            cout << cnt << ": " << i << endl;
            ++cnt;
        }

        cout << "\nivec2:" << endl;
        cnt = 0;
        for (auto i : ivec2)
        {
            cout << cnt << ": " << i << endl;
            ++cnt;
        }

        cout << "\n";
        unsigned scores[11];
        for (auto i : scores)
            cout << i << endl;
    }


    if (false)
    {
        int arr[] = {0, 3, 6, 9, 12};
        int *p = arr;
        for (size_t i = 0; i < 5; ++i)
        {
            cout << "*p: " << *p << endl;
            ++p;
        }

        //auto p1(arr);
        //decltype(arr) p2;
    }

    if (false)
    {
        const size_t size = 10;
        int arr[size] = {1, 4, 5, 4, 5, 6, 7, 8, 9};

        // using pointer arithmetic to traverse array
        // arr[size] is one element 'off-the-end'
        for (int *p = arr; p != &arr[size]; ++p)
            cout << *p << endl;

        cout << endl;

        int *beg = begin(arr);
        while (beg != end(arr) && beg != &arr[4])
        {
            ++beg;
        }

        cout << *beg << endl;

        //auto n = end(arr) - begin(arr);

        int *b = begin(arr);
        int *e = end(arr);
        while (b < e)
        {
            cout << *b << endl;
            ++b;
        }

        int i1 = arr[2];     // these are equivalent
        int i2 = *(arr + 2); // expressions

        cout << "i1: " << i1 << " i2: " << i2 << endl;

        //int *p1 = &arr[4];  // pointer to element indexed by arr[4]
        //int j = p1[3];      // equivalent to *(p1 + 3);
                                // p1[3] is the same element as arr[7]
        //int k = p1[-2];     // p1[-2] is the same element as arr[2]
    }

    if (0)
    {
        // ex. 3.34 pg 173
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto *p1 = &arr[9];
        auto *p2 = &arr[2];

        p1 += p2 - p1;

        cout << *p1 << endl;
    }

    if (false)
    {
        // ex. 3.35
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        //for (int *i = arr; i != end(arr); ++i) // also works
        for (auto i = arr; i != end(arr); ++i)
            *i = 0;

        for (auto i : arr)
            cout << i << " ";

        cout << endl;

        for (auto &i : arr)
            i = 4;

        for (auto i : arr)
            cout << i << " ";

        cout << endl;

        int *beg = begin(arr);
        //while (beg < end(arr)) // also works
        while (beg != end(arr))
        {
            *beg = 3;
            ++beg;
        }

        for (auto i : arr)
            cout << i << " ";

        cout << endl;
    }

    if (false)
    {
        // ex. 3.36
        int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int *a1b = begin(arr1);
        int *a2b = begin(arr2);

        bool equal = true;
        while (a1b != end(arr1))
        {
            if (*a1b != *a2b)
                equal = false;
            if (!equal)
                break;
            ++a1b;
            ++a2b;
        }

        if (equal)
            cout << "The arrays are equal, fam." << endl;
        else
            cout << "Them shits ain't equal bruv." << endl;

        cout << endl;

        vector<int> ivec1;
        vector<int> ivec2;

        for (int i = 0; i != 10; ++i)
        {
            ivec1.push_back(i);
            ivec2.push_back(i);
        }

        //ivec1[3] = 69;

        if (ivec1 == ivec2)
            cout << "These vectors are one-to-one, the real fuckin' deal." << endl;
        else
            cout << "Nah dude, I ain't about this shit right here. Next." << endl;
    }

    if (false)
    {
        // ex. 3.39 pg 176
        string s1 = "ass";
        string s2 = "cunt";

        if (s1 == s2)
            cout << "strings equal" << endl;
        else if (s1 < s2)
            cout << s1 << " < " << s2 << endl;
        else if (s1 > s2)
            cout << s1 << " > " << s2 << endl;

        char cs1[] = "dick";
        char cs2[] = "balls";

        int cmp = strcmp(cs1, cs2);
        if (cmp > 0)
            cout << cs1 << " > " << cs2 << endl;
        else if (cmp < 0)
            cout << cs1 << " < " << cs2 << endl;
        else
            cout << "c strings equal" << endl;
    }

    if (false)
    {
        // ex 3.40 pg 176
        char s1[] = "please fuck";
        char s2[] = "my ass";
        char s3[] = {'a', 'n', 'd', '\0'};

        const int s = 30;
        char cat[s];

        strcpy(cat, s1);
        strcat(cat, " ");
        strcat(cat, s2);
        strcat(cat, s3);

        cout << cat << endl;
    }

    string s = {'c', 'o', 'k'};
    string r = s + "ok";
    cout << r << "s" << endl;


    return 0;
}

