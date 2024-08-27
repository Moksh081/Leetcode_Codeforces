class Solution {
public:
    void findCombination(int i, int x, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        int n = arr.size();
        if (x == 0) {
            ans.push_back(ds);
            return;
        }
        for (int j = i; j < n; j++) {
            if (j > i && arr[j] == arr[j - 1]) continue;  // Skip duplicates
            if (arr[j] > x) break;  // No need to proceed further if the current number is greater than the target
            ds.push_back(arr[j]);
            findCombination(j + 1, x - arr[j], arr, ds, ans);  // Move to the next index for the next recursion
            ds.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int x) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());  // Sort the array to handle duplicates and ensure non-decreasing order
        findCombination(0, x, arr, ds, ans);
        return ans;
    }
};

