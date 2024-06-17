class Solution {
public:
     int heightChecker(std::vector<int>& heights) {
        // Make a copy of the original heights vector
        std::vector<int> sorted_heights = heights;

        // Sort the copied vector
        std::sort(sorted_heights.begin(), sorted_heights.end());

        // Count the number of differences between the original and sorted vectors
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (sorted_heights[i] != heights[i]) {
                count++;
            }
        }
        return count;
    }
};
