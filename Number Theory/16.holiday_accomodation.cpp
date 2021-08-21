/*
    Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city 
    and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:
        1. All the people should go to one of the other people's city.
        2. Two of them never go to the same city, because they are not willing to share a house.
        
    They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and 
    the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.

    Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.

    Input
        The first line of input contains one integer T (1 ≤ T ≤ 10), indicating the number of test cases.

        Each test case contains several lines. The first line contains an integer N (2 ≤ N ≤ 105), representing the number of cities. Then the 
        following N-1 lines each contains three integers X, Y, Z (1 ≤ X, Y ≤ N, 1 ≤ Z ≤ 106), means that there is a highway between city X and city Y, 
        and length of that highway.

        You can assume all the cities are connected and the highways are bi-directional.

    Output
        For each test case in the input, print one line: "Case #X: Y", where X is the test case number (starting with 1) and Y represents the largest 
        total travel distance of all people.

    Example
        Input:
            2
            4
            1 2 3
            2 3 2
            4 3 2
            6
            1 2 3
            2 3 4
            2 4 1
            4 5 8
            5 6 5

        Output:
            Case #1: 18
            Case #2: 62


    Problem: https://www.spoj.com/problems/HOLI/

    Approach:
        For every edge the contribution in travel_distance is 
            min(both side # of vertices) * 2 * weight
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int v)
    {
        this->V = v;
        this->adj = new list<pair<int, int>>[V];
    }

    void addEdge(int v, int u, int w)
    {
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    int DFSUtill(int s, vector<bool> &visited, int &travel_distance)
    {
        visited[s] = true;

        int no_Of_childs = 1;

        for (auto it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if (!visited[it->first])
            {
                int temp = DFSUtill(it->first, visited, travel_distance);
                no_Of_childs += temp;
                travel_distance += (min(temp, (V - temp)) * 2 * it->second);
            }
        }

        return no_Of_childs;
    }

    int DFS()
    {
        vector<bool> visited(V, false);

        int travel_distance = 0;

        DFSUtill(0, visited, travel_distance);

        return travel_distance;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Graph g(n);
        int x, y, z;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y >> z;
            g.addEdge(x-1, y-1, z);
        }

        cout << g.DFS() << endl;
    }

    return 0;
}
