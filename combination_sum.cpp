class Solution {
public:
    void findCombination(int ind, int x, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        int n = arr.size();
        if (x == 0) {
            ans.push_back(ds);
            return;
        }
        if (ind == n) {
            return;
        }
        // Include the current element if it doesn't exceed the target
        if (arr[ind] <= x) {
            ds.push_back(arr[ind]);
            findCombination(ind, x - arr[ind], arr, ds, ans);  // Stay at the same index because we can reuse the element
            ds.pop_back();  // Backtrack to explore other possibilities
        }
        // Move to the next element
        findCombination(ind + 1, x, arr, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, arr, ds, ans);
        return ans;
    }
};

