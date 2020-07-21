/*
    Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
    Find and print the Minimum Spanning Tree (MST).
*/

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dst, weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

// Union Find Algorithm
int getParent(int e, int *parent)
{
    while (e != parent[e])
        e = parent[e];
    return e;
}

Edge *get_MST(Edge *arr, int v, int e)
{
    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    int count = 0, index = 0;
    Edge *output = new Edge[v - 1];
    while (count < v - 1 && index < e)
    {
        Edge current_edge = arr[index];
        int src_parent = getParent(current_edge.src, parent);
        int dst_parent = getParent(current_edge.dst, parent);
        if (src_parent != dst_parent)
        {
            output[count] = current_edge;
            count++;
            parent[current_edge.src] = parent[current_edge.dst];
        }
        index++;
    }
    return output;
}

int main()
{
    int v, e;
    cin >> v >> e;
    Edge *arr = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        cin >> arr[i].src >> arr[i].dst >> arr[i].weight;
    }

    sort(arr, arr + e, compare);
    Edge *output = get_MST(arr, e, v);

    for (int i = 0; i < v - 1; i++)
    {
        if (output[i].src < output[i].dst)
            cout << output[i].src << " " << output[i].dst << " " << output[i].weight << endl;
        else
            cout << output[i].dst << " " << output[i].src << " " << output[i].weight << endl;
    }
}