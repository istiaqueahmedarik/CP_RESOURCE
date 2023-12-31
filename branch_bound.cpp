#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr; // weight vs value

class Node
{
public:
    int curWeight;  // means how much weight has been taken till now
    int curValue;   // means how much value has been taken till now
    int upperBound; // means the maximum value that can be obtained from this node
    int curInd;     // means the current index of the item
    Node(int curWeight, int curValue, int upperBound, int curInd) : curWeight(curWeight), curValue(curValue), upperBound(upperBound), curInd(curInd) {}
};

int upperBound(int curInd, int n, int curWeight, int curValue, int kanpW)
{
    if (curInd == n)
        return curValue;
    return curValue + (kanpW - curWeight) * (arr[curInd].second / arr[curInd].first);
}

int main()
{
    int n, kanpW;
    cin >> n >> kanpW;
    for (int i = 0; i < n; i++)
    {
        int w, p;
        cin >> w >> p;
        arr.push_back({w, p});
    }
    sort(arr.rbegin(), arr.rend(), [](pair<int, int> a, pair<int, int> b)
         { return (a.second / a.first) < (b.second / b.first); });

    queue<Node> q;
    q.push(Node(0, 0, upperBound(-1, n, 0, 0, kanpW), -1));
    int ans = 0;
    while (!q.empty())
    {
        Node curNode = q.front();
        q.pop();
        int curW = curNode.curWeight;
        int curV = curNode.curValue;
        int curUB = curNode.upperBound;
        int curInd = curNode.curInd;
        if (curInd == n - 1)
        {
            ans = max(ans, curV);
            continue;
        }
        // if we choose the next item
        int upperBoundIfTaken = upperBound(curInd + 1, n, curW + arr[curInd + 1].first, curV + arr[curInd + 1].second, kanpW);
        if (upperBoundIfTaken + curV >= ans && curW + arr[curInd + 1].first <= kanpW)
        {
            q.push(Node(curW + arr[curInd + 1].first, curV + arr[curInd + 1].second, upperBoundIfTaken, curInd + 1));
        }
        // if we don't choose the next item
        int upperBoundIfNotTaken = upperBound(curInd + 1, n, curW, curV, kanpW);
        if (upperBoundIfNotTaken + curV >= ans && curW <= kanpW)
        {
            q.push(Node(curW, curV, upperBoundIfNotTaken, curInd + 1));
        }
    }
    cout << ans;
}