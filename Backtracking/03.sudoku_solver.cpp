/*
    Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), 
    you need to solve the Sudoku puzzle.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyLocation(int sudoku[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (sudoku[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
    return false;
}

bool isPossible(int sudoku[N][N], int row, int col, int val)
{
    for (int i = 0; i < N; i++)
        if (sudoku[row][i] == val || sudoku[i][col] == val)
            return false;

    int row_factor = row - row % 3;
    int col_factor = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[i + row_factor][j + col_factor] == val)
                return false;

    return true;
}

bool solveSudoku(int sudoku[N][N])
{
    int row, col;
    if (!findEmptyLocation(sudoku, row, col))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        return true;
    }

    for (int i = 1; i <= N; i++)
        if (isPossible(sudoku, row, col, i))
        {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    return false;
}

int main()
{
    int sudoku[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solveSudoku(sudoku);
    return 0;
}