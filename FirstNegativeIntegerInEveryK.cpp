#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    long long left = 1, right = k;
    queue<long long> q;
    vector<long long> ans;
    map<long long, long long> mp;
    for (long long i = 0; i < k; i++)
    {
        mp[arr[i]]++;
        if (arr[i] < 0)
            q.push(arr[i]);
    }
    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(q.front());
    if (arr[left - 1] == q.front())
        q.pop();
    while (right < n)
    {
        if (arr[right] < 0)
            q.push(arr[right]);
        left++;
        right++;
        if (q.empty())
        {
            ans.push_back(0);
            continue;
        }
        ans.push_back(q.front());
        if (arr[left - 1] == q.front())
            q.pop();
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}