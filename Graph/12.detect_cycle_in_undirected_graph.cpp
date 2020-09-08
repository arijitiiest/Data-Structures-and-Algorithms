/*
    Given a directed graph, check whether the graph contains a cycle or not.
*/

#include <bits/stdc++.h>
using namespace std;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

class Graph
{
    int V;
    list<int> *adj;
    bool DFSUtil(int v, vector<int> color);

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
    adj[w].push_back(v); // For undirected graph
}

bool Graph::DFSUtil(int v, vector<int> color)
{
    color[v] = GRAY;

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (color[*it] == GRAY)
            return true;

        if (color[*it] == WHITE && DFSUtil(*it, color))
            return true;
    }
    color[v] = BLACK;
    return false;
}

bool Graph::isCycle()
{
    vector<int> color(V, WHITE);

    for (int u = 0; u < V; u++)
        if (color[u] == WHITE && DFSUtil(u, color))
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
