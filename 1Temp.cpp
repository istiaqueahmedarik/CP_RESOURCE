#include <bits\stdc++.h>
using namespace std;
int pascal(int n, int r)
{
    if (n <= 0 || r <= 0)
        return 1;
    return pascal(n - 1, r - 1) + pascal(n - 1, r);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
    }
}