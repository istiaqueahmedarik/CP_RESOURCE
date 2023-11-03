#include <bits/stdc++.h>
#define lili long long int
#define ld long double
using namespace std;

const int M = 1e6 + 2;
lili spf[M];

void sieve()
{
    for (lili i = 0; i < M; i++)
    {
        spf[i] = 0;
    }
    for (lili i = 2; i * i < M; i++)
    {
        if (spf[i] == 0)
        {
            for (lili j = i * i; j < M; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    for (lili i = 1; i < M; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
        }
    }
}

struct Node
{
    lili gcd;
    lili pf;
    //    Node() {
    //        gcd = 0;
    //        pf = 1;
    //    }
};

const int N = 1e5 + 3;
lili a[N];
Node tree[4 * N];

lili lcm(lili a, lili b)
{
    lili prod = a * b;
    lili g = __gcd(a, b);
    lili res = prod / g;
    return res;
}

void build(lili nd, lili start, lili endd)
{
    cout << "node = " << nd << " start = " << start << " end = " << endd << endl;
    if (start == endd)
    {
        lili x = a[start];
        // prime factorize;
        while (spf[x] > 1)
        {
            lili k = spf[x];
            tree[nd].pf *= k;
            while (x % k)
            {
                x /= k;
            }
        }
        return;
    }
    lili Left = 2 * nd;
    lili Right = 2 * nd + 1;
    lili Mid = (start + endd) / 2;
    //    cout << "node = " << node << " start = " <<  endl;
    //    cout << left << " " << start << " " << mid << endl;
    build(Left, start, Mid);
    build(Right, Mid + 1, endd);
    tree[nd].pf = lcm(tree[Left].pf, tree[Right].pf);
    tree[nd].gcd = __gcd(tree[Left].gcd, tree[Right].gcd);
    return;
}

Node query(lili node, lili start, lili endd, lili l, lili r)
{
    if (start >= l && endd <= r)
    {
        return tree[node];
    }
    if (endd < l || start > r)
    {
        Node newnode;
        return newnode;
    }
    int left = 2 * node, right = left + 1, mid = (start + endd) / 2;
    Node node1 = query(left, start, mid, l, r);
    Node node2 = query(right, mid + 1, endd, l, r);
    Node merged_node;
    merged_node.gcd = __gcd(tree[left].gcd, tree[right].gcd);
    merged_node.pf = lcm(tree[left].pf, tree[right].pf);
    return merged_node;
}
template <class T>
class SegmentTree
{
    vector<T> arr, tree;

public:
    SegmentTree(vector<T> &arr)
    {
        this->arr.resize(arr.size());
        this->arr = arr;
        tree.resize(4 * arr.size());
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        build(node << 1, start, (start + end) >> 1);
        build((node << 1) + 1, ((start + end) >> 1) + 1, end);
        tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    }
    void update(int node, int start, int end, int idx, T val)
    {
        if (start == end)
        {
            arr[idx] = tree[node] = val;
            return;
        }
        if (idx <= (start + end) >> 1)
            update(node << 1, start, (start + end) >> 1, idx, val);
        else
            update((node << 1) + 1, ((start + end) >> 1) + 1, end, idx, val);
        tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    }
    //[l,r]
    T query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;
        return (l <= start && end <= r) ? tree[node] : query(node << 1, start, (start + end) >> 1, l, r) + query((node << 1) + 1, ((start + end) >> 1) + 1, end, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    //    for(int i = 1; i <= 20; i++) {
    //        cout << "i = " << i << " spf = " << spf[i] << endl;
    //    }
    //    for(int i = 0; i < 4 * N; i++) {
    //        tree[i].gcd = 0;
    //        tree[i].pf = 1;
    //    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "hi" << endl;
    build(1, 1, n);
    lili l, r;
    cin >> l >> r;
    //    Node nd = query(1, 1, n, l, r);
    //    cout << "gcd = " << nd.gcd << " pf = " << nd.pf << endl;
}