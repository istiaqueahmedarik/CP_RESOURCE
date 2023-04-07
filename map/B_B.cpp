#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int32_t main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    map<string, string> country;        // which people belongs to which country
    map<string, int> each_person_vote;  // how many votes each person has
    map<string, int> each_country_vote; // how many votes each country has
    while (n--)
    {
        string s, s1;
        cin >> s >> s1;
        country[s] = s1;
    }
    while (m--)
    {
        string s;
        cin >> s;
        each_person_vote[s]++;
        each_country_vote[country[s]]++;
    }
    string mx_country;
    int mx_country_vote = 0;
    for (auto i : each_country_vote)
    {
        if (i.second > mx_country_vote)
        {
            mx_country = i.first;
            mx_country_vote = i.second;
        }
    }
    string mx_person;
    int mx_person_vote = 0;
    for (auto i : each_person_vote)
    {
        if (i.second > mx_person_vote)
        {
            mx_person = i.first;
            mx_person_vote = i.second;
        }
    }
    for (auto i : each_person_vote)
    {
        if (i.second == mx_person_vote && i.first < mx_person)
        {
            mx_person = i.first;
        }
    }
    cout << mx_country << endl;
    cout << mx_person << endl;
    return 0;
}