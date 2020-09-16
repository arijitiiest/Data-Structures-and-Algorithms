/*
    Given a DAG, print topological sort of the graph using Kahn Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

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
    void addEdge(int v, int u)
    {
        adj[v].push_back(u);
    }
    void topologicalSort();
};

void Graph::topologicalSort()
{
    stack<int> st;
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    vector<int> indegree(V, 0);
    for (int v = 0; v < V; v++)
        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
            indegree[*it]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    vector<int> order;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
            if (--indegree[*it] == 0)
                q.push(*it);

        count++;
    }

    if (count != V)
    {
        cout << "There exists a a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "All Topological Sorts : \n";
    g.topologicalSort();
}
