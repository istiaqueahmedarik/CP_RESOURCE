#include <bits/stdc++.h>
using namespace std;
bool similar(map<int, int> &mp, map<int, int> &mp2)
{
    for (auto i : mp2)
    {
        if (i.second != mp[i.first])
            return false;
    }
    return true;
}
int main()
{
    string txt, patt;
    cin >> txt >> patt;
    int left = 1, right = patt.size();
    int n = txt.size();
    map<int, int> freq, freq1;
    for (int i = 0; i < right; i++)
    {
        freq[txt[i]]++;
    }
    for (int i = 0; i < patt.size(); i++)
        freq1[patt[i]]++;
    int c = similar(freq, freq1) ? 1 : 0;
    while (right <= n - 1)
    {
        string sub = txt.substr(left, patt.size());
        freq[txt[left++ - 1]]--;
        freq[txt[right++]]++;
        c += similar(freq, freq1) ? 1 : 0;
    }
    cout << c << endl;
}