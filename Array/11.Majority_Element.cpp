/*
    Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element may exist in the array.

    Example 1:
        Input: [3,2,3]
        Output: 3

    Example 2:
        Input: [2,2,1,1,1,2,2]
        Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int findCandidate(int a[], int size)
{
    int count = 0;
    int maj = a[0];

    for (int i = 0; i < size; i++)
    {
        if (count == 0)
            maj = a[i];
        if (a[i] == maj)
            count++;
        else
            count--;
    }
    return maj;
}

/* Function to check if the candidate 
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

        if (a[i] == cand)
            count++;

    if (count > size / 2)
        return 1;

    else
        return 0;
}

/* Function to print Majority Element */
void printMajority(int a[], int size)
{
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size);

    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand))
        cout << " " << cand << "\n";

    else
        cout << "No Majority Element\n";
}

/* Driver code */
int main()
{
    int a[] = {2, 2, 1, 1, 1, 2, 2};
    int size = (sizeof(a)) / sizeof(a[0]);

    // Function calling
    printMajority(a, size);

    return 0;
}