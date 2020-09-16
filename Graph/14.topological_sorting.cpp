/*
    Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
    vertex u comes before v in the ordering.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &st);

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

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st)
{
    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        if (!visited[*it])
            topologicalSortUtil(*it, visited, st);

    st.push(v);
}

void Graph::topologicalSort()
{
    stack<int> st;
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    for (int v = 0; v < V; v++)
        if (!visited[v])
            topologicalSortUtil(v, visited, st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
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

    cout << "Following is a Topological Sort of the given graph : ";
    g.topologicalSort();
    cout << endl;
}
