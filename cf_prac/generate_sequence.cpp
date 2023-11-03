#include <bits/stdc++.h>
using namespace std;
bool valid_bracket(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}
int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        s += '(';
    }
    for (int i = 0; i < n; i++)
    {
        s += ')';
    }
    vector<string> ans;
    do
    {
        if (valid_bracket(s))
        {
            ans.push_back(s);
        }
    } while (next_permutation(s.begin(), s.end()));
}