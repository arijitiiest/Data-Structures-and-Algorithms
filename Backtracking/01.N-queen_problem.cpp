/*
    You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack 
    any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the 
    same diagonal of any of the other queens. You have to print all such configurations.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int **arr, int n, int row, int col)
{
    // Same Column
    for (int i = 0; i <= row; i++)
        if (arr[i][col] == 1)
            return false;

    // Same Row
    for (int i = 0; i <= col; i++)
        if (arr[row][i] == 1)
            return false;

    // Diagonal
    for (int i = 0; row - i >= 0 && col - i >= 0; i++)
    {
        if (arr[row - i][col - i])
            return false;
    }
    for (int i = 0; row + i < n && col + i < n; i++)
    {
        if (arr[row + i][col + i])
            return false;
    }
    for (int i = 0; row - i >= 0 && col + i < n; i++)
    {
        if (arr[row - i][col + i])
            return false;
    }
    for (int i = 0; row + i < n && col - i >= 0; i++)
    {
        if (arr[row + i][col - i])
            return false;
    }

    return true;
}

void placeNQueen(int **arr, int n, int row = 0)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isPossible(arr, n, row, col))
        {
            arr[row][col] = 1;
            placeNQueen(arr, n, row + 1);
            arr[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    placeNQueen(arr, n);

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}