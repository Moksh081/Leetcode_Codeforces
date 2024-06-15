class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> map(3, 0); // Correctly size the map to 3
        
        // Count occurrences of each color
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        // Overwrite nums with sorted elements
        int index = 0;
        for (int color = 0; color < 3; color++) {
            while (map[color] > 0) {
                nums[index++] = color;
                map[color]--;
            }
        }
    }
};

