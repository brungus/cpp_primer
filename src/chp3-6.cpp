#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main()
{
    if (false)
    {
        // ex. 3.41 pg 179
        int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        vector<int> vec;

        for (auto it = begin(arr); it != end(arr); ++it)
            vec.push_back(*it);

        for (auto i : vec)
            cout << i << " ";

        cout << endl;
    }

    if (false)
    {
        // ex. 3.42 pg 179
        vector<int> ivec;
        for (int i = 0; i < 10; ++i)
            ivec.push_back(i);

        int arr[10];
        for (auto it = 0; it != 10; ++it)
            arr[it] = ivec[it];

        for (auto i : arr)
            cout << i << " ";

        cout << endl;
    }

    if (false)
    {
        constexpr size_t row = 3, col = 4;
        int ia[row][col];

        size_t cnt = 0;
        for (auto &row : ia)
        {
            for (auto &col : row)
            {
                col = cnt;
                ++cnt;
                cout << cnt << " ";
            }
        }
        cout << endl;

        // p is a pointer to an array of 4 ints
        // it points to the first int [4]
        // it is incremented by int (*)[4], pointing to the next int [4]
        //for (int (*p)[4] = ia; p != ia + row; ++p) // equivalent
        for (auto p = ia; p != ia + row; ++p)
        {
            // q starts out by pointing to the first int [4]
            // since using an array is automatically converted, 
            // it points to first element of the int [4]
            // it is incremented through until it points to one past the end
            // p is not converted to int * from int (*)[4], even though they
            // point at the same place, you must derefence p to get int *
            for (auto q = *p; q != *p + col; ++q) // q is a pointer to int
            {
                cout << *q << ' ';
            }
            cout << endl;
        }

        for (auto p = begin(ia); p != end(ia); ++p)
        {
            for (auto q = begin(*p); q != end(*p); ++q)
            {
                cout << *q << ' ';
            }
            cout << endl;
        }
    }

    if (false)
    {
        // ex. 3.43 pg 184
        constexpr int row = 3, col = 4;
        int ia[row][col];
        int cnt = 0;
        for (auto &row : ia)
        {
            for (auto &i : row)
            {
                i = cnt;
                ++cnt;
            }
        }

        for (int (&r)[col] : ia)
        {
            for (int i : r)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                cout << ia[r][c] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        // r is a pointer to an array of 4 ints, int (*)[4]
        // each time it is incremented to the next int (*)[4]
        for (int (*r)[4] = ia; r != ia + row; ++r)
        {
            // c is a pointer to int, it is initialized with the r array
            // this is converted to point to the first element of r
            // so when incremented, it points to the next element
            // until it is one past the last element
            for (int *c = *r; c != *r + col; ++c)
            {
                cout << *c << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    if (false)
    {
        // ex 3.44 pg 184
        using int_array = int[4];
        using int_ptr = int*;

        constexpr size_t row = 3, col = 4;
        int ia[row][col];
        int cnt = 0;
        for (auto &row : ia)
        {
            for (auto &i : row)
            {
                i = cnt;
                ++cnt;
            }
        }

        for (int_array &r : ia)
        {
            for (int i : r)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for (int_array *r = ia; r != ia + row; ++r)
        {
            for (size_t c = 0; c != col; ++c)
            {
                cout << (*r)[c] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for (int_array *r = ia; r != ia + row; ++r)
        {
            // when dereferencing r, you get an int [4]
            // which is converted to an int *, which points to the first element
            for (int_ptr c = *r; c != *r + col; ++c)
            {
                cout << *c << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    // ex. 3.45 pg 184
    constexpr size_t row = 3, col = 4;
    int ia[row][col];
    int cnt = 0;
    for (auto &row : ia)
    {
        for (auto &i : row)
        {
            i = cnt;
            ++cnt;
        }
    }

    for (auto &r : ia)
    {
        for (auto c : r)
        {
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto r = 0; r != row; ++r)
    {
        for (auto c = 0; c != col; ++c)
        {
            cout << ia[r][c] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto r = ia; r != ia + row; ++r)
    {
        for (auto c = *r; c != *r + col; ++ c)
        {
            cout << *c << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto r = begin(ia); r != end(ia); ++r)
    {
        for (auto c = begin(*r); c != end(*r); ++c)
        {
            cout << *c << ' ';
        }
        cout << endl;
    }
    cout << endl;
            
    return 0;
}
