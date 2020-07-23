/*
    A sink node is a node such that no edge emerges out of it. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    list<int> *r_adj;
    void _DFS1(int s, bool *visited, stack<int> &finished_vertices);
    void _DFS2(int s, bool *visited, unordered_set<int> *components);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int u);
    unordered_set<unordered_set<int> *> *getSCC();
    void printBottom();
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

void Graph::_DFS2(int s, bool *visited, unordered_set<int> *components)
{
    visited[s] = true;
    components->insert(s);

    list<int>::iterator it;
    for (it = r_adj[s].begin(); it != r_adj[s].end(); it++)
    {
        if (!visited[*it])
        {
            _DFS2(*it, visited, components);
        }
    }
}

unordered_set<unordered_set<int> *> *Graph::getSCC()
{
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    stack<int> finished_vertices;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            _DFS1(i, visited, finished_vertices);
        }
    }

    memset(visited, false, sizeof(visited));
    unordered_set<unordered_set<int> *> *components = new unordered_set<unordered_set<int> *>();
    while (!finished_vertices.empty())
    {
        int s = finished_vertices.top();
        finished_vertices.pop();

        if (!visited[s])
        {
            unordered_set<int> *component = new unordered_set<int>();
            _DFS2(s, visited, component);
            components->insert(component);
        }
    }
    return components;
}

void Graph::printBottom()
{
    unordered_set<unordered_set<int> *> *components = getSCC();

    vector<int> ans;

    for (auto it1 = components->begin(); it1 != components->end(); it1++)
    {
        bool flag = false;
        for (auto it2 = (*it1)->begin(); it2 != (*it1)->end(); it2++)
        {
            for (auto it3 = adj[*it2].begin(); it3 != adj[*it2].end(); it3++)
            {
                if ((*it1)->count(*it3) == 0)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            for (auto it2 = (*it1)->begin(); it2 != (*it1)->end(); it2++)
                ans.push_back(*it2);
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Bottom of the graph are: \n";
    g.printBottom();

    return 0;
}
