Question: 1
Write pseudocode for Dijkstra's algorithm? (Naive Approach)  
Answer: 1

```pseudo
void dijkstra(int source)
{
    for each node v in graph G
        dist[v] = infinity
        prev[v] = undefined
        add node v to queue Q
    dist[source] = 0
    while Q is not empty
        u = node in Q with smallest dist[]
        remove u from Q
        for each neighbor v of u
            alt = dist[u] + length(u, v)
            if alt < dist[v]
                dist[v] = alt
                prev[v] = u
}
```

Write some limitations of the Dijkstra algorithm? (at least 10).

=>

1. Dijkstra's algorithm does not work with negative edge weights. If the graph contains a negative-weight cycle, then it is possible to find a shorter path by taking a negative-weight cycle.
2. Dijkstra's algorithm does not work with directed graphs. If the graph is directed, then Dijkstra's algorithm will not find the shortest path between two vertices.
3. Dijkstra's algorithm does not work with disconnected graphs. If the graph is disconnected, then Dijkstra's algorithm will not find the shortest path between two vertices.

Question: 2
What is Topological Sort?Explain with Example.
=>

Topological sort is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG(Directed Acyclic Graph).
Example:
Input: 6 6
1 2
1 3
2 4
2 5
3 5
4 6
Output: 1 2 3 4 5 6

Can a topological sort be implemented in a Directed cyclic graph (DCG)?If so, explain How would you do it?
=>

No, a topological sort cannot be implemented in a Directed cyclic graph (DCG). If we try to implement a topological sort in a DCG, we will get a cycle. A topological sort is only possible in a Directed Acyclic Graph (DAG).
Now let's see how we can implement a topological sort in a DCG. We can implement a topological sort in a DCG by removing all the edges from the graph and then performing a topological sort on the remaining graph. This will give us a topological sort of the graph.

Question: 3
Draw a Directed Cyclic Graph(DCG) and Directed Acyclic Graph(DAG)

=>
here is the DCG and DAG:

Explain the differences between Directed Cyclic Graphs (DCG) and Directed Acyclic Graphs (DAG). (At least 3)
=>

1. A Directed Acyclic Graph (DAG) is a directed graph with no directed cycles. A directed cycle is a cycle where you can start at a vertex v and follow a sequence of edges that eventually take you back to v again.
2. A Directed Acyclic Graph (DAG) is a directed graph with no directed cycles. A directed cycle is a cycle where you can start at a vertex v and follow a sequence of edges that eventually take you back to v again.
3. A Directed Acyclic Graph (DAG) is a directed graph with no directed cycles. A directed cycle is a cycle where you can start at a vertex v and follow a sequence of edges that eventually take you back to v again.

Question: 4
What is the purpose of a base case in a recursive function, and what happens if it is not included? 10
=>

The purpose of a base case in a recursive function is to stop the recursion. If the base case is not included, then the recursion will continue forever.
for example:

```cpp
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

here is the base case: if (n == 1) { return 1; }

What is recursion, and how is it different from iteration?
=>

Recursion is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem. Recursion is different from iteration because recursion involves a function calling itself, while iteration involves a loop.

?How can you detect whether a graph is bipartite?

=>

```pseudo
function isBipartite(G):
    for each vertex v in G:
        color[v] = WHITE
        for each vertex v in G:
            if color[v] == WHITE:
                if not dfs(v, RED):
                    return false
        return true

```
