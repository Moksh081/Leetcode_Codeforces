/*
class Solution {
public:
    int helper(int sum, int k, vector<int>& nums){
        int ans=0;
        unordered_map<int,int> dp;
        for(auto num: nums){
            int x = num%k;
            dp[x] = max(dp[x],dp[(sum-x+k)%k]+1);
            ans = max(ans,dp[x]);
        }
        return ans;
    }

    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size();i++){
            ans = max(ans,helper(i,k,nums));
        }
        return ans;
    }
};
*/
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int maxLen = 0;
        
        for (int num : nums) {
            for (int j = 0; j < k; ++j) {
                int remainder = num % k;
                maxLen = max(maxLen, dp[remainder][j] = dp[j][remainder] + 1);
            }
        }
        
        return maxLen;
    }
};
