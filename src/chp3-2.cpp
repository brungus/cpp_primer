#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    //string line;
    //while (getline(cin, line))
    //while (cin >> line)
        //cout << line << endl;

    //string s1, s2;
    //cout << "Enter two strings to compare: ";
    //cin >> s1 >> s2;

    //if (s1 == s2)
        //cout << "The strings are equal." << endl;
    //else
    //{
        //cout << "That shit ain't equal, cuz." << endl;
        //if (s1 > s2)
            //cout << "The first one be bigger." << endl;
        //else
            //cout << "The second be bigger." << endl;
    //}

    //string input, concat;
    //while (cin >> input)
        //concat += input + " ";

    //for (int i = 0; i < concat.size(); ++i)
        //concat[i] = std::toupper(concat[i]);
    //cout << concat << endl;

    //cout << "Back to lower: " << endl;

    //string tmp;
    //for (auto c : concat)
        //tmp += std::tolower(c);
    //concat = tmp;
    //cout << concat << endl;

    //cout << "Back to upper: " << endl;

     //no need for temp string when control variable is a reference
    //for (auto &c : concat)
        //c = std::toupper(c);
    //cout << concat << endl;

    //cout << "Now just the first character: " << endl;
    //if (!concat.empty())
        //concat[0] = tolower(concat[0]);
    //cout << concat << endl;

    //cout << "First word tolower: " << endl;
     //using a proper type for iteration
    //for (decltype(concat.size()) i = 0; 
         //i != concat.size() && !std::isspace(concat[i]); ++i)
    //{
        //concat[i] = std::tolower(concat[i]);
    //}
    //cout << concat << endl;


    //string s = "Stinky britches for sale!!";
    //cout << s << endl;
    //cout << "All characters to X: " << endl;
    //for (auto &c : s)
        //c = 'X';
    //cout << s << endl;

    //decltype(s.size()) i = 0;
    //while (i != s.size())
    //{
        //s[i] = 'X';
        //++i;
    //}
    //cout << s << endl;

    //for (decltype(s.size()) i = 0; i != s.size(); ++i)
        //s[i] = 'X';
    //cout << s << endl;


    string s;
    getline(cin, s);

    for (auto c : s)
        if (!std::ispunct(c))
            cout << c;
    cout << endl;

    const char &c = s[0];

    const string cS = "Keep out!";
    for (char &c : s)
        c = 's';
    cout << cS << endl;


    //int arr[3]{1, 2, 3};
    //int t = 1;
    //for (auto i : arr)
    //{
        //cout << t + i << endl;
        //t += 1;
    //}


    return 0;
}
