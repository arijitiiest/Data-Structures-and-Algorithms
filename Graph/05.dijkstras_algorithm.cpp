/*
    Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and 
    E number of edges. Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices 
    (including source vertex also) using Dijkstra's Algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

int get_min_vertex(bool *visited, int *dist, int v)
{
    int min_vertex = -1;
    int min_distance = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && dist[i] < min_distance)
        {
            min_distance = dist[i];
            min_vertex = i;
        }
    }

    return min_vertex;
}

void dijkstra(int **arr, int v)
{
    bool *visited = new bool[v];
    int *dist = new int[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    int i = 0;
    while (i < v - 1)
    {
        int min_vertex = get_min_vertex(visited, dist, v);
        visited[min_vertex] = true;

        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && arr[min_vertex][j] != 0 && dist[j] > dist[min_vertex] + arr[min_vertex][j])
            {
                dist[j] = dist[min_vertex] + arr[min_vertex][j];
            }
        }
        i++;
    }

    for (int i = 0; i < v; i++)
        cout << i << " " << dist[i] << endl;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int **arr = new int *[v];
    for (int i = 0; i < v; i++)
    {
        arr[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        arr[v1][v2] = w;
        arr[v2][v1] = w;
    }
    dijkstra(arr, v);
}