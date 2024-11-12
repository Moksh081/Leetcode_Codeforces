class Solution {
public:
    int helper(int n, vector<vector<int>>& items) {
        // Binary search for the item with the highest price <= n
        int left = 0, right = items.size() - 1;
        int maxBeauty = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= n) {
                maxBeauty = items[mid][1]; // Update max beauty found
                left = mid + 1;            // Move right to find a higher price within the range
            } else {
                right = mid - 1;           // Move left if the price exceeds n
            }
        }
        
        return maxBeauty;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items by price
        sort(items.begin(), items.end());

        // Step 2: Precompute the maximum beauty up to each price point
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        
        vector<int> op(queries.size(), 0);

        // Step 3: Process each query using binary search
        for (int i = 0; i < queries.size(); i++) {
            op[i] = helper(queries[i], items);
        }
        
        return op;
    }
};

