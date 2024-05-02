#include <iostream>
#include <vector>

using namespace std;

// Function to check if it is safe to place a queen at board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the left side of the current row
    for (int i = 0; i < col; ++i) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve the n-queens problem using backtracking
bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    // Base case: If all queens are placed
    if (col >= n) {
        return true;
    }

    // Try placing queen in each row of the current column
    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col, n)) {
            // Place queen at board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, n)) {
                return true;
            }

            // If placing queen at board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0; // Backtrack
        }
    }

    // If queen can't be placed in any row of the current column, return false
    return false;
}

// Function to print the solution vector
void printSolution(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        cout << "Solution for N Queens problem:\n";
        printSolution(board, n);
    } else {
        cout << "No solution exists for the given size of the chessboard.\n";
    }

    return 0;
}
