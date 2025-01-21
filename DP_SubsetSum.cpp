class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;

        // Calculate the total sum
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        // If the total sum is odd, we cannot partition it into two equal subsets
        if (totSum % 2 != 0) return false;

        int target = totSum / 2;

        // Initialize DP table
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: A sum of 0 is always possible (empty subset)
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // Base case: For the first element
        if (nums[0] <= target) dp[0][nums[0]] = true;

        // Fill the DP table
        for (int index = 1; index < n; index++) {
            for (int j = 1; j <= target; j++) {
                // Not take the current element
                bool notTake = dp[index - 1][j];

                // Take the current element if it doesn't exceed the current target
                bool take = false;
                if (j >= nums[index]) {
                    take = dp[index - 1][j - nums[index]];
                }

                dp[index][j] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

/* space optimized

*/
/*
class Solution {
public:
    bool subsetsum(int n, int target, vector<int>& nums) {
        vector<bool> prev(target + 1, false);
        prev[0] = true;

        for (int i = 0; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int j = 1; j <= target; j++) {
                bool nt = prev[j]; // Not take
                bool t = false;    // Take

                if (nums[i] <= j) {
                    t = prev[j - nums[i]];
                }

                curr[j] = t || nt;
            }
            prev = curr; // Update prev after processing current row
        }

        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int tsum = 0;
        for (int num : nums) {
            tsum += num;
        }

        // If total sum is odd, we cannot partition into two equal subsets
        if (tsum % 2 != 0) return false;

        int target = tsum / 2;
        return subsetsum(nums.size(), target, nums);
    }
};

