/*
class Solution {
public:
    bool isvalid(vector<int>& a, vector<int>& b) {
        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < a.size(); i++) {
            sum_a += a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            sum_b += b[i];
        }
        return sum_a >= sum_b;
    }

    int waysToSplitArray(vector<int>& nums) {
        vector<int> temp1, temp2(nums.begin() + 1, nums.end());
        int count = 0;

        temp1.push_back(nums[0]);
        if (isvalid(temp1, temp2)) {
            count++;
        }

        for (int i = 1; i < nums.size() - 1; i++) {
            temp1.push_back(nums[i]);
            temp2.erase(temp2.begin());
            if (isvalid(temp1, temp2)) {
                count++;
            }
        }

        return count;
    }
};
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // Prefix sum array to store cumulative sums
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long long leftSum = prefSum[i];
            // Sum of right part (i+1 to n-1)
            long long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
