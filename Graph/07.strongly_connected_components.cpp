/*
    A directed graph is strongly connected if there is a path between all pairs of vertices.
    We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    list<int> *r_adj;
    void _DFS1(int s, bool *visited, stack<int> &finished_vertices);
    void _DFS2(int s, bool *visited);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int u);
    void getSCC();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    r_adj = new list<int>[V];
}

Graph::~Graph()
{
    delete[] adj;
    delete[] r_adj;
}

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
    r_adj[u].push_back(v);
}

void Graph::_DFS1(int s, bool *visited, stack<int> &finished_vertices)
{
    visited[s] = true;

    list<int>::iterator it;
    for (it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if (!visited[*it])
        {
            _DFS1(*it, visited, finished_vertices);
        }
    }
    finished_vertices.push(s);
}

void Graph::_DFS2(int s, bool *visited)
{
    visited[s] = true;
    cout << s << " ";

    list<int>::iterator it;
    for (it = r_adj[s].begin(); it != r_adj[s].end(); it++)
    {
        if (!visited[*it])
        {
            _DFS2(*it, visited);
        }
    }
}

// Kosarajus's algorithm
void Graph::getSCC()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    stack<int> finished_vertices;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            _DFS1(i, visited, finished_vertices);
        }
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    while (!finished_vertices.empty())
    {
        int s = finished_vertices.top();
        finished_vertices.pop();

        if (!visited[s])
        {
            _DFS2(s, visited);
            cout << "\n";
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly connected components are: \n";
    g.getSCC();

    return 0;
}