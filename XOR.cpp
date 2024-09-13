class Solution {
public:
    int xorr(vector<int>& arr, int i, int j) {
        int sum = 0; // Initialize sum to 0
        while(i <= j) { // Iterate from i to j inclusive
            sum ^= arr[i]; // XOR the current element
            i++;
        }
        return sum;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> result(m); // Initialize result with size m
        for(int i = 0; i < m; i++) {
            result[i] = xorr(arr, queries[i][0], queries[i][1]); // Directly assign the XOR result
        }
        return result;
    }
};

