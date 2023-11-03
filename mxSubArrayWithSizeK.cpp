#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int left = 0, right = k;
    int sm = 0;
    for (int i = 0; i < k; i++)
        sm += v[i];
    int ans = sm;
    while (right < n)
    {
        sm = sm - v[left] + v[right];
        left++;
        right++;
        ans = max(ans, sm);
    }
    ans = max(ans, sm);
    cout << ans << endl;
}

/*
    1 2 3 4 5
    1 2 -->3
    3-1+3-->5
    5-2+4-->7
    7-3+5-->9
*/