class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int maxDist = 0;

        for (int i = 1; i < n; ++i) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();
            
            // Calculate the maximum distance considering current array and previous min/max
            maxDist = max(maxDist, abs(currentMax - minVal));
            maxDist = max(maxDist, abs(maxVal - currentMin));
            
            // Update the overall min and max values
            minVal = min(minVal, currentMin);
            maxVal = max(maxVal, currentMax);
        }

        return maxDist;
    }
};
