class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Sort the cuts in descending order
        sort(horizontalCuts.rbegin(), horizontalCuts.rend());
        sort(verticalCuts.rbegin(), verticalCuts.rend());

        int totalCost = 0;
        int horizontalSegments = 1;
        int verticalSegments = 1;

        // Use two pointers to iterate through horizontal and vertical cuts
        int h = 0, v = 0;
        
        while (h < horizontalCuts.size() && v < verticalCuts.size()) {
            if (horizontalCuts[h] > verticalCuts[v]) {
                totalCost += horizontalCuts[h] * verticalSegments;
                horizontalSegments++;
                h++;
            } else {
                totalCost += verticalCuts[v] * horizontalSegments;
                verticalSegments++;
                v++;
            }
        }

        // Add remaining horizontal cuts if any
        while (h < horizontalCuts.size()) {
            totalCost += horizontalCuts[h] * verticalSegments;
            h++;
        }

        // Add remaining vertical cuts if any
        while (v < verticalCuts.size()) {
            totalCost += verticalCuts[v] * horizontalSegments;
            v++;
        }

        return totalCost;
    }
};
