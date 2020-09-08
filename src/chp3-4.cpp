#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void printVec(const vector<int> &v);
void printVec(const vector<unsigned> &v);

int main()
{
    if (false)
    {
        // ex. 3.21 pg 159
        vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            *it *= *it;
            cout << *it << " ";
        }
        cout << endl;
    }

    if (false)
    {
        // ex. 3.22
        vector<string> text;
        string sentence;
        while (getline(cin, sentence))
            text.push_back(sentence);
        for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
        {
            for (auto &c : *it)
            {
                c = toupper(c);
            }
        }

        for (auto sentence : text)
        {
            string tab = "    ";
            if (!sentence.empty())
                cout << tab << sentence << endl;
        }
    }

    if (false)
    {
        // ex. 3.23
        vector<int> ivec;
        int num;
        while (cin >> num)
            ivec.push_back(num);

        for (auto it = ivec.begin(); it != ivec.end(); ++it)
        {
            cout << *it << " * 2 = ";
            *it *= 2;
            cout << *it << endl;
        }
    }

    if (false)
    {
        // ex. 3.24 pg 162
        vector<int> ivec;
        int num;
        while (cin >> num)
            ivec.push_back(num);
        
        cout << "Original numbers: ";
        printVec(ivec);

        cout << "\nAdjacent sums:";
        for (auto it = ivec.begin(); it != ivec.end(); ++it)
        {
            if ((it + 1) != ivec.end())
                cout << *it << " + " << *(it + 1) << " = " << *it + *(it + 1) << endl;
        }


        printVec(ivec);
        cout << "\nInverse sums:\n";
        for (auto it = ivec.begin(); it != ivec.end(); ++it)
        {
            auto beg = ivec.begin();
            auto end = ivec.end();
            auto diff = (end - it) - 1; // integral type, the "difference_type"
                                        // needed to add to begin() to get the
                                        // desired iterator element
                                        // order of operations seems to matter here
                                        // if (it - 1) is evaluated first, you get
                                        // different (wrong) results compared to
                                        // (end - it) first
            //auto inv = beg + diff;
            auto inv = ivec.begin() + (ivec.end() - it) - 1;
            //auto inv = beg + ((end - it) - 1); 
            cout << *it << " + " << *inv << " = "
                 << *it + *inv << endl;
        }
    }

    if (true)
    {
        // ex. 3.25
        vector<unsigned> scores(11, 0);
        unsigned grade;
        while (cin >> grade)
        {
            if (grade <= 100)
            {
                auto it = scores.begin();
                it += grade / 10; // may be off by one, +1
                *it += 1;
            }
        }
        printVec(scores);
    }
    

    return 0;
}

void printVec(const vector<unsigned> &v)
{
    cout << "size: " << v.size() << " elements: ";
    unsigned num = 0;
    for (auto i : v)
    {
        if (num != v.size() - 1)
            cout << i << ", ";
        else
            cout << i << endl;
        ++num;
    }
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
