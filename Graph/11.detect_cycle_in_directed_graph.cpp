/*
    Given an directed graph. Check if there is a cycle in the graph.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool isCycleUtil(int v, vector<bool> visited, vector<bool> recStack);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool isCycle();
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
    adj[v].push_back(w);
    // adj[w].push_back(v); // For undirected graph
}

bool Graph::isCycleUtil(int v, vector<bool> visited, vector<bool> recStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it] && isCycleUtil(*it, visited, recStack))
                return true;
            else if (recStack[*it])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCycle()
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int u = 0; u < V; u++)
        if (isCycleUtil(u, visited, recStack))
            return true;

    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << (g.isCycle() ? "Graph contains cycle\n" : "Graph doesn't contain cycle\n");
}
