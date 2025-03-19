#include <iostream>
#include <vector>
using namespace std;

int sol = 0;

bool isSafe(vector<int> queens, int row, int col)
{
    for (int prev_col = 0; prev_col < col; prev_col++)
    {
        if (queens[prev_col] == row || abs(queens[prev_col] - row) == abs(prev_col - col))
        {
            return false;
        }
    }
    return true;
}
void solve(vector<int> queens, int col, int n)
{
    if (col == n)
    {
        sol++;
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(queens, row, col))
        {
            queens[row] == col;
            solve(queens, col + 1, n);
            queens[row] = -1;
        }
    }
}
void printSolution(vector<int> queens, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (queens[j] == i)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int n = 4;
    vector<int> queens(n, -1);
    cout << "Solving N-Queens for n = " << n << ":\n\n";
    solve(queens, 0, n);
    if (sol == 0)
    {
        cout << "No solution exists\n"; // Fixed spacing
    }
    else
    {
        cout << "Total solutions: " << sol << endl; // Fixed wording and spacing
    }
    return 0;
}