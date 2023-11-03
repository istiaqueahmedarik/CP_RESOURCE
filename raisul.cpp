#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define float double
const ll INFI = 1e18;
const ll MOD = 1e9 + 7;
map<char, set<char>> mp;
map<char, ll> vis;
void dfs(char ch)
{
    cout << ch;
    vis[ch] = 1;
    for (auto i : mp[ch])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
void init()
{
    mp.clear();
    vis.clear();
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1, CT = 0;
    cin >> t;
    // cin.ignore();
    while (t--)
    {
        init();
        string st;
        cin >> st;
        for (ll i = 0; i < st.size() - 1; ++i)
        {
            mp[st[i]].insert(st[i + 1]);
            mp[st[i + 1]].insert(st[i]);
        }
        ll c = 0;
        char x;
        for (auto it : mp)
        {
            if (it.second.size() == 1)
            {
                c++;
                x = it.first;
            }
        }
        if (st.size() == 1)
        {
            cout << "YES\n";
            vis[st[0]] = 1;
            cout << st[0];
            for (ll i = 0; i < 26; i++)
            {
                x = i + 'a';
                if (!vis[x])
                {
                    cout << x;
                }
            }
            cout << "\n";
        }
        else
        {
            if (c == 2 or (mp.size() < 26 and c == 1))
            {
                cout << "YES\n";
                dfs(x);
                for (ll i = 0; i < 26; i++)
                {
                    x = i + 'a';
                    if (!vis[x])
                    {
                        cout << x;
                    }
                }
                cout << "\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}