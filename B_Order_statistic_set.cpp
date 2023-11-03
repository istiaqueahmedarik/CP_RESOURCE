#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main()
{
    IOS;
    o_set<ll> s;
    int t;
    cin >> t;
    while (t--)
    {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == 'I')
        {
            s.insert(x);
        }
        else if (c == 'K')
        {

            if (x > s.size())
                cout << "invalid" << endl;
            else
                cout << *s.find_by_order(x - 1) << endl;
        }
        else if (c == 'C')
        {
            cout << s.order_of_key(x) << endl;
        }
        else if (c == 'D')
        {
            s.erase(x);
        }
    }
    return 0;
}