#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s1; string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5("butts");
    string s6(s5);

    cin >> s1 >> s2;
    cout << s1 << s2 << endl;

    string line;
    while (getline(cin, line))
    {
        if (!line.empty())
            cout << line << endl;

        auto size{line.size()};
        cout << "Last line's size: " << size << endl;
    }



    return 0;
}
