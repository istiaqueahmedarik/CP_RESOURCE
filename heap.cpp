#include <bits/stdc++.h>
using namespace std;

int parent(int idx) { return (idx - 1) / 2; }
int leftChild(int idx) { return 2 * idx + 1; }
int rightChild(int idx) { return 2 * idx + 2; }
bool leftChildExists(vector<int> &arr, int n, int idx)
{
    return leftChild(idx) < n;
}
bool rightChildExists(vector<int> &arr, int n, int idx)
{
    return rightChild(idx) < n;
}
void heapify(vector<int> &arr, int n, int idx)
{
    int mx1 = arr[idx];
    int mx2 = leftChildExists(arr, n, idx) ? arr[leftChild(idx)] : INT_MIN;
    int mx3 = rightChildExists(arr, n, idx) ? arr[rightChild(idx)] : INT_MIN;
    int mx = max({mx1, mx2, mx3});
    if (mx == mx1)
        return;
    else if (mx == mx2)
    {
        swap(arr[idx], arr[leftChild(idx)]);
        heapify(arr, n, leftChild(idx));
    }
    else
    {
        swap(arr[idx], arr[rightChild(idx)]);
        heapify(arr, n, rightChild(idx));
    }
}
vector<int> buildHeap(vector<int> &arr, int n)
{
    vector<int> cp = arr;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(cp, n, i);
    }
    return cp;
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    arr = buildHeap(arr, n);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}
