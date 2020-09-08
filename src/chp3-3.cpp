// library vector type

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct taint
{
    char t = 'a';
    int i = 3;

};

void printVec(const vector<int> &v);
void printVec(const vector<string> &v);

int main()
{
    if (false)
    {
        vector<int> vec;
        vector<int> vec2(vec);
        vector<int> vec3{1, 2, 3};
        //vector<int> vec4(1, 2, 3); // not allowed
        
        vector<string> vec5(10, "yo"); // 10 elements, each initialized to "yo"

        vector<int> vec6(10); // 10 elements, each initialized to 0
        // value-initialized element initializer -----------------^
        
        vector<string> vec7(10); // 10 elements, each an empty string, ""
        // value-initialized element initializer ----------------------^
        
        vector<string> iVec;
        string n;
        while (cin >> n)
            iVec.push_back(n);
        for (int i = 0; i < iVec.size(); ++i)
            cout << iVec[i] << endl;

        string d = iVec[0];
        d = "big d";

        cout << iVec[0] << endl;
    }

    if (false)
    {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);

        vector<int> vec2 = vec;
        
        if (vec == vec2)
            cout << "vec == vec2" << endl;

        cout << "vec2[0] = 3" << endl;
        vec2[0] = 3;

        if (vec == vec2)
            cout << "vec == vec2" << endl;
        else
            cout << "vec != vec2" << endl;
    }

    if (false)
    {
        // ex. 3.16 pg 153
        vector<int> v1;
        vector<int> v2(10);         // 10 ints, all 0 (default initialized)
        vector<int> v3(10, 42);     // 10 ints, all 42
        vector<int> v4{10};         // 1 int, 10
        vector<int> v5{10, 42};     // 2 ints, 10, 42
        vector<string> v6{10};      // cannot use int to initialize string
                                    // so compiler looks for other way to initialize
                                    // object from given value
                                    // 10 empty strings
        vector<string> v7{10, "hi"};// 10 "hi" strings
        //vector<string> v8{10, "hi", "yo"}; // illegal, no matching constructor and
        //                                   // compiler cannot discern how to initialize

        printVec(v1);
        printVec(v2);
        printVec(v3);
        printVec(v4);
        printVec(v5);
        printVec(v6);
        printVec(v7);
    }

    if (false)
    {
        // ex. 3.17
        vector<string> vec;
        string word;
        while (cin >> word)
            vec.push_back(word);

        for (auto &s : vec)
        {
            for (auto &c : s)
            {
                c = toupper(c);
            }
        }

        int wordCount = 0;
        for (auto w : vec)
        {
            cout << w << " ";
            ++wordCount;
            if (wordCount % 8 == 0)
            {
                cout << endl;
            }
        }

        cout << "\n\n";

        for (decltype(vec.size()) i; i != vec.size(); ++i)
        {
            cout << vec[i] << " ";
            if ((i+1) % 8 == 0)
                cout << endl;
        }

        cout << endl;
    }

    // ex. 3.18
    if (false)
    {
        vector<int> ivec {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
        vector<int> ivec2(10, 42);
        vector<int> ivec3;
        for (int i = 0; i < 10; ++i)
            ivec3.push_back(42);

        printVec(ivec);
        printVec(ivec2);
        printVec(ivec3);
    }

    vector<int> ivec;
    int inNum;
    while (cin >> inNum)
        ivec.push_back(inNum);

    cout << "numbers: ";
    printVec(ivec);

    cout << "\nAdjacent sums:" << endl;
    int last = 0;
    for (auto num : ivec)
    {
        if (last != 0)
        {
            cout << last << " + " << num << " = " << num + last << endl;
        }
        last = num;
    }

    cout << endl;

    printVec(ivec);
    cout << "\nInverse sums: (first + last, second + second-last, etc..." << endl;
    for (decltype(ivec.size()) i = 0; i != ivec.size(); ++i)
        cout << ivec[i] << " + " << ivec[ivec.size() - i - 1] << " = "
             << ivec[i] + ivec[ivec.size() - i - 1] << endl;

    return 0;
}

void printVec(const vector<string> &v)
{
    cout << "size: " << v.size() << " elements: ";
    for (auto i : v)
        cout << i << ", ";
    cout << endl;
}

void printVec(const vector<int> &v)
{
    cout << "size: " << v.size() << " elements: ";
    int num = 0;
    for (auto i : v)
    {
        if (num != v.size() - 1)
            cout << i << ", ";
        else
            cout << i << endl;
        ++num;
    }
}
