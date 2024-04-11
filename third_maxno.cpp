class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>()); // Sort in descending order
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end()); // Remove duplicates
        
        if (nums.size() < 3) {
            return nums[0]; // If less than 3 unique elements, return the maximum
        } else {
            return nums[2]; // Return the third maximum
        }
    }
};
