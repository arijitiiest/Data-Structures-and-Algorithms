/*
    A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a 
    number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations 
    on such a data structure:

    Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

    Union: Join two subsets into a single subset.

    This Algo is used to detect cycle in Graph in O(logn) time
*/

// Graph should be Undirected. This method assumes that the graph doesn’t contain any self-loops.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void Union(struct subset subsets[], int x, int y);
    int find(struct subset subsets[], int i);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool isCycle();
};

struct subset
{
    int parent;
    int rank;
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Undirected Graph and no self loops
}

// (uses path compression technique)
int Graph::find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// (uses union by rank)
void Graph::Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool Graph::isCycle()
{
    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    list<int>::iterator it;
    for (int v = 0; v < V; v++)
    {
        int x = find(subsets, v);
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            int y = find(subsets, *it);

            if (x == y)
                return true;

            Union(subsets, x, y);
        }
    }
    return false;
}

int main()
{
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    if (g.isCycle())
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
    return 0;
}