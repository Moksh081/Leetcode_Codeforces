#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canShipInDays(int cap, vector<int>& weights, int days) {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int weight : weights) {
            if (currentLoad + weight > cap) {
                requiredDays++;
                currentLoad = weight;
                if (requiredDays > days) {
                    return false;
                }
            } else {
                currentLoad += weight;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
        }

        int l = *max_element(weights.begin(), weights.end());
        int r = sum;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canShipInDays(mid, weights, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

