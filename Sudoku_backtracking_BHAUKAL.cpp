class Solution {
public:
    // Function to check if it's valid to place 'c' at board[row][col]
    bool isvalid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == c) {
                return false;
            }
            // Check the column
            if (board[i][col] == c) {
                return false;
            }
            // Check the 3x3 subgrid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }

    // Backtracking function to solve the Sudoku
    bool solvee(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // If the cell is empty
                if (board[i][j] == '.') {
                    // Try placing numbers '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {
                        if (isvalid(board, i, j, c)) {
                            board[i][j] = c;

                            // Recursively attempt to solve the rest of the board
                            if (solvee(board)) {
                                return true;
                            } else {
                                // If not solvable, backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If no valid number is found, return false
                    return false;
                }
            }
        }
        // Return true when the board is fully solved
        return true;
    }

    // Function to solve the Sudoku and return the solved board
    void solveSudoku(vector<vector<char>>& board) {
        solvee(board);
    }
};
./
