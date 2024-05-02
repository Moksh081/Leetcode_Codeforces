class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        // Iterate from the end of the sorted vector
        for (int i = n - 1; i >= 0; i--) {
            // If the current number is positive and its negative counterpart exists in the vector
            if (nums[i] > 0 && binary_search(nums.begin(), nums.end(), -nums[i])) {
                return nums[i];
            }
        }
        // If no such number is found, return -1 or any default value
        return -1; // or any other default value indicating not found
    }
};
