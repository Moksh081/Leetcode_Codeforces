class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        int minStart = INT_MAX;
        int maxEnd = INT_MIN;
        int n = intervals.size();

        // Find the minimum start time and maximum end time
        for (int i = 0; i < n; i++) {
            minStart = std::min(minStart, intervals[i][0]);
            maxEnd = std::max(maxEnd, intervals[i][1]);
        }

        // Create an event count array
        std::vector<int> eventCount(maxEnd + 2, 0);

        // Populate the event count array
        for (int i = 0; i < n; i++) {
            eventCount[intervals[i][0]]++;          // Start of an interval
            eventCount[intervals[i][1] + 1]--;      // End of an interval
        }

        int maxOverlaps = 0;
        int currentOverlap = 0;

        // Calculate the maximum overlaps
        for (int i = minStart; i <= maxEnd + 1; i++) {
            currentOverlap += eventCount[i];
            maxOverlaps = std::max(maxOverlaps, currentOverlap);
        }

        return maxOverlaps;
    }
};
