/*
    Given an directed graph. Check if there is a cycle in the graph.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int v, int u);
    bool isCyclic();
};

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    visited[v] = true;

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (!visited[*it])
        {
            if (isCyclicUtil(*it, visited, v))
                return true;
        }
        else if (*it != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    for (int v = 0; v < V; v++)
        if (!visited[v] && isCyclicUtil(v, visited, -1))
            return true;

    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    // g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout << (g.isCyclic() ? "Graph contains cycle\n" : "Graph doesn't contain cycle\n");
}
