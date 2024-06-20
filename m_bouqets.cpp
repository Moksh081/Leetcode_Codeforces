#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if it's possible to make m bouquets with k flowers by mid day
    bool isPossible(const vector<int>& bloomDay, int dayLimit, int m, int k) {
        int bouquets = 0, flowers = 0;
        for (int day : bloomDay) {
            if (day <= dayLimit) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        return false;
    }

    // Function to find the minimum number of days to make m bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) {
            return -1;  // Not enough flowers to make the bouquets
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                right = mid;  // Try for a smaller maximum day
            } else {
                left = mid + 1;  // Increase the minimum day
            }
        }

        return left;
    }
};

