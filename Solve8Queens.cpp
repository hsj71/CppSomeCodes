#include <iostream>
#include <vector>
using namespace std;
#define N 8
// Function to print the chessboard
void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }  cout << endl;
    }  cout << endl;
}
// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check the current column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
               }
    }
    return true;
}

// Recursive function to solve the 8-Queens problem
bool solve8Queens(vector<vector<int>>& board, int row, int firstRow, int firstCol) {
    // If all queens are placed
    if (row >= N) {
        return true;
    }
    // If this row is where the first queen is already placed, skip to the next row
    if (row == firstRow) {
        return solve8Queens(board, row + 1, firstRow, firstCol);
    }
    // Try placing a queen in each column
    for (int col = 0; col < N; ++col) {
        // Skip the column where the first queen is placed
        if (row != firstRow && col == firstCol) {
            continue;
        }
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solve8Queens(board, row + 1, firstRow, firstCol)) {
                return true;
            }

            // Backtrack: remove the queen
             board[row][col] = 0;
        }
    }

    // If no column is suitable
    return false;
}

int main() {
    // Initialize the chessboard
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first queen (row and column are user-defined)
    int firstRow, firstCol;
    cout << "Enter the row and column of the first queen (0-based index): ";
    cin >> firstRow >> firstCol;

    // Place the first queen
    if (firstRow >= 0 && firstRow < N && firstCol >= 0 && firstCol < N) {
        board[firstRow][firstCol] = 1;

        // Solve the problem for the remaining queens, skipping the row and column of the first queen
        if (solve8Queens(board, 0, firstRow, firstCol)) {
            cout << "The final 8-Queens matrix is: " << endl;
            printBoard(board);
        } else {
            cout << "No solution exists with the given initial placement." << endl;
        }
    } else {
        cout << "Invalid position for the first queen." << endl;
    }
    return 0;
}
