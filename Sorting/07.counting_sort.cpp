/*
    Sort the elements of an character array using counting sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255

void counting_sort(char *arr)
{
    int n = strlen(arr);
    char output[n];

    int count[RANGE + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= RANGE; i++)
        count[i] += count[i - 1];

    for (int i = 0; arr[i]; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; arr[i]; i++)
        arr[i] = output[i];
}

int main()
{
    char arr[] = "ArijitChowdhury";

    counting_sort(arr);

    cout << arr << endl;

    return 0;
}
