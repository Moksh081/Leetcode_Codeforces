class Solution {
public:
    void findCombination(int i, int x, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans, int k, int count) {
        if (x == 0 && count == k) {
            ans.push_back(ds);
            return;
        }
        if (count > k) return;  // If count exceeds k, stop further exploration

        int n = arr.size();
        for (int j = i; j < n; j++) {
            if (j > i && arr[j] == arr[j - 1]) continue;  // Skip duplicates
            if (arr[j] > x) break;  // No need to proceed further if the current number is greater than the target
            
            ds.push_back(arr[j]);
            findCombination(j + 1, x - arr[j], arr, ds, ans, k, count + 1);  // Move to the next index with incremented count
            ds.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0, n, arr, ds, ans, k, 0);
        return ans;
    }
};

