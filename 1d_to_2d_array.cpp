class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {}; 
        }
        vector<vector<int>> matrix(m, vector<int>(n));
         int index = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = original[index++];
            }
        }
        //or
        /*
        for (int i = 0; i < original.size(); ++i) {
            matrix[i / n][i % n] = original[i];
        }
        //or
        /*
         for (int i = 0; i < m; ++i) {
            matrix.push_back(vector<int>(original.begin() + i * n, original.begin() + (i + 1) * n));
        }
        */
        return matrix;
    }
};

