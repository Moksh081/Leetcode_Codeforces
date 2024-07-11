class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int p = floor(nums.size() / 3);
        vector<int> arr;
        unordered_map<int, int> map;

        // Count the frequency of each element
        for (int num : nums) {
            map[num]++;
        }

        // Check which elements appear more than floor(n/3) times
        for (auto it : map) {
            if (it.second > p) {
                arr.push_back(it.first);
            }
        }

        return arr;
    }
};
