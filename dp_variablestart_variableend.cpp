class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Number of rows
        int m = matrix[0].size();  // Number of columns

        vector<int> prev(m, 0);  // Represents the previous row's minimum path sums
        vector<int> cur(m, 0);  // Represents the current row's minimum path sums

        // Initialize the first row (base condition)
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Up direction
                int up = matrix[i][j] + prev[j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j] + (j - 1 >= 0 ? prev[j - 1] : 1e9);

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j] + (j + 1 < m ? prev[j + 1] : 1e9);

                // Store the minimum of the three paths in the current row
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            // Update the 'prev' array with the values from the 'cur' array
            prev = cur;
        }

        // Find the minimum value in the last row of 'prev'
        return *min_element(prev.begin(), prev.end());
    }
};

