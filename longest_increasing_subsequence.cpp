/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        stack<int> st;
        int count = 1;
        int max[nums.size()];
        for(int i=0; i<nums.size();i++){
            for(int j=1; j<nums.size();){
                st.push(nums[i]);
                if(nums[j]>nums[i]){
                    st.push(nums[j]);
                    count++;
                }else{
                    j++;
                }
            }
            max[i] = count;
          }
          int t = 0;
          for(int i=0; i<nums.size();i++){
              if(max[i]>t){
                  t = max[i];
              }
          }
          return t;
        }
};
*/
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        std::vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
