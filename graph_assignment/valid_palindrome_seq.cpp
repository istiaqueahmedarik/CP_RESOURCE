#include <bits/stdc++.h>
using namespace std;

bool possiblePalindrome(string s)
{
    int n = s.length();
    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] % 2 != 0)
        {
            odd++;
        }
    }
    if (odd > 1)
    {
        return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (possiblePalindrome(s))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}