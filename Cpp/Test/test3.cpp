#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string s1 = " ";
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s;
    int i = 0;
    while (i <= s.length() - 1)
    {
        string s2 = s.substr(i, 2);
        int x = stoi(s2);
        if ((x >= 65 && x <= 91) || (x >= 97 && x <= 99))
        {
            s1 += char(x);
        }
        else
        {
            s2 = s.substr(i, 3);
            s1 += char(stoi(s2));
            i = i + 1;
        }
        i = i + 2;
    }
    cout << s1;
    return 0;
}

