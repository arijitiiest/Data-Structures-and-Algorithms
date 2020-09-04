/*
    Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
    the ith histogram’s bar. Width of each bar is 1.
    Find the area of largest rectangle in the histogram.

    Input:
        A = [2, 1, 5, 6, 2, 3]
    Output:
        10

    Algorithm:
        1) Create an empty stack.

        2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
            a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
            b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
               Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left 
               index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

        3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangle(int arr[], int n)
{
    stack<int> st;
    int mx_area = 0;
    int tp, area;

    int i = 0;
    while (i < n)
    {
        if (st.empty() || arr[st.top()] <= arr[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            tp = st.top();
            st.pop();

            area = arr[tp] * (st.empty() ? i : i - st.top() - 1);

            if (area > mx_area)
            {
                mx_area = area;
            }
        }
    }

    while (!st.empty())
    {
        tp = st.top();
        st.pop();

        area = arr[tp] * (st.empty() ? i : i - st.top() - 1);

        if (area > mx_area)
        {
            mx_area = area;
        }
    }
    return mx_area;
}

int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << largestRectangle(arr, n) << endl;
}
