/*
    Given a DAG, print all topological sorts of the graph
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(vector<int> &res, bool visited[], vector<int> &indegree);

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

void Graph::topologicalSortUtil(vector<int> &res, bool visited[], vector<int> &indegree)
{
    bool flag = false;

    for (int v = 0; v < V; v++)
    {
        if (indegree[v] == 0 && !visited[v])
        {
            for (auto it = adj[v].begin(); it != adj[v].end(); it++)
                indegree[*it]--;

            res.push_back(v);
            visited[v] = true;
            topologicalSortUtil(res, visited, indegree);

            visited[v] = false;
            res.pop_back();
            for (auto it = adj[v].begin(); it != adj[v].end(); it++)
                indegree[*it]++;

            flag = true;
        }
    }

    if (!flag)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

void Graph::topologicalSort()
{
    stack<int> st;
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    vector<int> indegree(V, 0), res;
    for (int v = 0; v < V; v++)
        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
            indegree[*it]++;

    topologicalSortUtil(res, visited, indegree);
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
