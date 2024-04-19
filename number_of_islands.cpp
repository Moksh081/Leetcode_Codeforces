class Solution {
public:
    void mark_current_island(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        mark_current_island(grid, i + 1, j, m, n);
        mark_current_island(grid, i, j + 1, m, n);
        mark_current_island(grid, i - 1, j, m, n);
        mark_current_island(grid, i, j - 1, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    mark_current_island(grid, i, j, m, n);
                    count++;
                }
            }
        }
        
        return count;
    }
};

