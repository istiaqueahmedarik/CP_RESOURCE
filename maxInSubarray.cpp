#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 1, right = k;
    priority_queue<int> pq;
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
        pq.push(arr[i]);
    }
    ans.push_back(pq.top());
    while (right < n)
    {
        mp[arr[left - 1]]--;
        mp[arr[right]]++;
        pq.push(arr[right]);
        while (mp[pq.top()] <= 0)
            pq.pop();
        left++;
        right++;
        ans.push_back(pq.top());
    }
}