/*
    A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. 
    Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms 
    in the hotel to satisfy the demand.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arrival[], int departure[], int n, int no_of_rooms)
{
    pair<int, int> p[2 * n];
    for (int i = 0; i < n; i++)
    {
        p[2 * i] = {arrival[i], 1};
        p[2 * i + 1] = {departure[i], -1};
    }

    sort(p, p + 2 * n);

    int count = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        count += p[i].second;
        if (count > no_of_rooms)
            return false;
    }

    return true;
}

int main()
{
    int arrival[] = {1, 3, 5};
    int departure[] = {2, 6, 8};
    int n = sizeof(arrival) / sizeof(arrival[0]);
    int no_of_rooms = 1;
    cout << (isPossible(arrival, departure, n, no_of_rooms) ? "Possible\n" : "Not Possible\n");
}