class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0, col = m - 1;

        // Traverse the matrix from (0, m-1):
        while (row < n && col >= 0) {
            // Check current element against neighbors with proper boundary checks
            bool top = (row > 0) ? mat[row][col] > mat[row - 1][col] : true;
            bool bottom = (row < n - 1) ? mat[row][col] > mat[row + 1][col] : true;
            bool left = (col > 0) ? mat[row][col] > mat[row][col - 1] : true;
            bool right = (col < m - 1) ? mat[row][col] > mat[row][col + 1] : true;
            
            if (top && bottom && left && right) {
                return {row, col};
            } else if (row < n - 1 && mat[row][col] < mat[row + 1][col]) {
                row++;
            } else {
                col--;
            }
        }
        return {};
    }
};
