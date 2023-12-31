#include<bits/stdc++.h>
using namespace std;

// Structure for iterative node for Branch and Bound
struct Node {
    int weight;
    int profit;
    int level;
    int bound;
};

Node* newNode(int weight, int profit, int level)
{
    Node* node = new Node;
    node->weight= weight;
    node->profit = profit;
    node->level= level;
    return node;
}

// Returns upper bound for profit in subtree profit at node node and profit
int bound(Node* node, int weight, int profit[], int weightList[], int n)
{
    if (node->weight >= weight)
        return 0;
    int profit_bound = node->profit;
    int availableWeight = weight - node->weight;
    int i = node->level + 1;

    while ((i<n) && (availableWeight >= weightList[i]))
    {
        availableWeight -= weightList[i];
        profit_bound += profit[i];
        i++;
    }

    // Check if next item can fit into the available weight
    if (i < n)
        profit_bound += (profit[i] * availableWeight) / weightList[i];

    return profit_bound;
}

int knapSack(int weight, int profit[], int weightList[], int n)
{
    queue<Node*> Q;
    Node* node = newNode(0, 0, -1);
    Q.push(node);

    int maxProfit = 0;
    while (!Q.empty()){
        node = Q.front();
        Q.pop();
        if (node->level < n - 1){
            Node* node1 = newNode(node->weight + weightList[node->level + 1],node->profit + profit[node->level + 1], node->level + 1);
            Node* node2 = newNode(node->weight, node->profit, node->level + 1);
            int bound1 = bound(node1, weight, profit, weightList, n);
            int bound2 = bound(node2, weight, profit, weightList, n);

            if (bound1 > maxProfit)
                maxProfit = node1->profit;

            if (bound1 >= maxProfit) Q.push(node1);
            if (bound2 >= maxProfit) Q.push(node2);
        }
    }
    return maxProfit;
}

int main()
{
    int weightList[] = {10, 20, 30};    //weights of the items
    int profit[] = {60, 100, 120};      //profits of the items
    int W = 50;                          //total weight of the knapsack
    int n = 3;                           //total number of items

    cout << knapSack(W, profit, weightList, n);

    return 0;
} 
