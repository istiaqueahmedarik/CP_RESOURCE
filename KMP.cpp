#include <bits/stdc++.h>
using namespace std;
void Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int kmp(string s, string pat)
{
    int lps[pat.size()];
    memset(lps, 0, sizeof(lps));
    int prevLPS = 0, curr = 1;
    while (curr < pat.size())
        if (pat[prevLPS] == pat[curr])
            lps[curr++] = prevLPS++ + 1;
        else if (!prevLPS)
            lps[curr++] = 0;
        else
            prevLPS = lps[prevLPS - 1];
    Print(lps, pat.size());
    int strPtr = 0, patPtr = 0;
    while (strPtr < s.size() and patPtr != pat.size())
        if (s[strPtr] == pat[patPtr])
            strPtr++, patPtr++;
        else if (!patPtr)
            strPtr++;
        else
            patPtr = lps[patPtr - 1];
    return patPtr == pat.size() ? strPtr - pat.size() : -1;
}

int main()
{
    string s, patt;
    cin >> s >> patt;
    cout << kmp(s, patt) << endl;
}