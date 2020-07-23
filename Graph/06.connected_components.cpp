/*
    Connected Components in an undirected graph
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void _DFS(int s, bool *visited);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int u);
    void connectedComponents();
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

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::_DFS(int s, bool *visited)
{
    visited[s] = true;
    cout << s << " ";

    list<int>::iterator it;
    for (it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if (!visited[*it])
        {
            _DFS(*it, visited);
        }
    }
}

void Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v])
        {
            _DFS(v, visited);

            cout << "\n";
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Connected Components are:\n";
    g.connectedComponents();

    return 0;
}