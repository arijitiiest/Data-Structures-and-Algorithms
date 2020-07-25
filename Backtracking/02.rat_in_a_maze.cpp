/*
    You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. 
    maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down). Value of every cell in the maze can either be 0 or 1. 
    Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 4

void solveMazeHelper(int maze[N][N], int sol[N][N], int row, int col)
{
    if (row < 0 || col < 0 || row >= N || col >= N || sol[row][col] == 1 || maze[row][col] == 0)
        return;

    if (row == N - 1 && col == N - 1)
    {
        sol[row][col] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        sol[row][col] = 0;
    }

    sol[row][col] = 1;
    solveMazeHelper(maze, sol, row + 1, col);
    solveMazeHelper(maze, sol, row, col + 1);
    solveMazeHelper(maze, sol, row - 1, col);
    solveMazeHelper(maze, sol, row, col - 1);
    sol[row][col] = 0;
}

void solveMaze(int maze[N][N])
{
    int sol[N][N];
    memset(sol, 0, sizeof(sol));

    solveMazeHelper(maze, sol, 0, 0);
}

int main()
{
    int n = 4;
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 1, 0},
                      {1, 1, 1, 1}};
    solveMaze(maze);
    return 0;
}
