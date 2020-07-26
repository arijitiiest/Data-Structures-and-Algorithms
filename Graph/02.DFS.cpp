/*
    DFS(Depth first search) is a graph traversing algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFShelper(bool *visited, int s);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void DFS(int s);
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

void Graph::DFShelper(bool *visited, int s)
{
    visited[s] = true;
    list<int>::iterator it;

    cout << s << " ";

    for (it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if (!visited[*it])
        {
            DFShelper(visited, *it);
        }
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFShelper(visited, s);
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

    cout << "BFS traversal: ";
    g.DFS(2);
    cout << endl;

    return 0;
}