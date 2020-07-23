/*
    Check whether a given graph is Bipartite or not
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int u);
    bool isBipartite();
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
}

bool Graph::isBipartite()
{
    if (V == 0)
        return true;

    unordered_set<int> sets[2];
    vector<int> pending;
    sets[0].insert(0);
    pending.push_back(0);
    while (!pending.empty())
    {
        int current = pending.back();
        pending.pop_back();
        int currentSet = sets[0].count(current) > 0 ? 0 : 1;
        for (auto it = adj[current].begin(); it != adj[current].end(); it++)
        {
            int neighbour = *it;
            if (sets[0].count(neighbour) == 0 && sets[1].count(neighbour) == 0)
            {
                sets[1 - currentSet].insert(neighbour);
                pending.push_back(neighbour);
            }
            else if (sets[currentSet].count(neighbour) > 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    Graph g(n);

    int e, u, v;
    cin >> e;
    while (e--)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    bool ans = g.isBipartite();
    if (ans)
        cout << "Bicolorable\n";
    else
        cout << "Not Bicolorable\n";

    return 0;
}