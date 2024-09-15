class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(), nums.end()); // Find the maximum element
        int maxCount = 0; // To track the length of the longest subarray
        int currCount = 0; // To track the length of the current subarray

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxElem) {
                currCount++; // Increase current count when element matches the maximum
                maxCount = max(maxCount, currCount); // Update the maximum length found
            } else {
                currCount = 0; // Reset current count when the element does not match the maximum
            }
        }

        return maxCount;
    }
};

