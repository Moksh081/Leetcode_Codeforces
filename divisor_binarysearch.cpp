class Solution {
public:
    int helper(int divisor, vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;  // Equivalent to ceil(num / divisor)
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            int sum = helper(mid, nums);
            if (sum <= threshold) {
                r = mid;  // Try to find a smaller divisor
            } else {
                l = mid + 1;  // Increase the divisor
            }
        }
        
        return l;  // When l meets r, we have the smallest divisor
    }
};

