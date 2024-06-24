#include <vector>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;  // Convert even numbers to 0
            } else {
                nums[i] = 1;  // Convert odd numbers to 1
            }
        }

        int left = 0, count = 0, oddCount = 0;
        for (int right = 0; right < n; ++right) {
            oddCount += nums[right];

            while (oddCount > k) {
                oddCount -= nums[left];
                ++left;
            }

            if (oddCount == k) {
                int tempLeft = left;
                while (tempLeft <= right && nums[tempLeft] == 0) {
                    ++tempLeft;
                }
                count += (tempLeft - left + 1);
            }
        }

        return count;
    }
};

