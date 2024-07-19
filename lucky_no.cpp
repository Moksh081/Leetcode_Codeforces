class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> rmin(n, INT_MAX);
        vector<int> cmax(m, INT_MIN);
        
        // Find the minimum values in each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rmin[i] = std::min(rmin[i], matrix[i][j]);
            }
        }

        // Find the maximum values in each column
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cmax[j] = std::max(cmax[j], matrix[i][j]);
            }
        }

        // Find all lucky numbers
        vector<int> lucky;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rmin[i] && matrix[i][j] == cmax[j]) {
                    lucky.push_back(matrix[i][j]);
                }
            }
        }
        
        return lucky;
    }
};

