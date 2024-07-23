#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (const auto& num : nums) {
            freqMap[num]++;
        }

        // Custom comparator for sorting
        auto cmp = [&](int a, int b) {
            if (freqMap[a] == freqMap[b])
                return a > b;  // If frequencies are the same, sort by value in decreasing order
            return freqMap[a] < freqMap[b];  // Otherwise, sort by frequency in increasing order
        };

        sort(nums.begin(), nums.end(), cmp);

        return nums;
    }
};

