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
    int t;
    cin >> t;
    while (t--)
    {
        int arr[3], arr1[3];
        for (int i = 0; i < 3; i++)
            cin >> arr[i];
        for (int i = 0; i < 3; i++)
            cin >> arr1[i];
        sort(arr, arr + 3);
        sort(arr1, arr1 + 3);
        if (arr[2] + arr[1] > arr1[2] + arr1[1])
        {
            cout << "Alice" << endl;
        }
        else if (arr[2] + arr[1] < arr1[2] + arr1[1])
        {
            cout << "Bob" << endl;
        }
        else
            cout << "Tie" << endl;
    }
    return 0;
}