#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int max_val = arr[n-1] + k;  // Large enough to include the k-th missing positive number
        
        // Create a new array to track presence
        vector<int> presence(max_val + 1, 0);
        
        // Mark the presence of elements in the input array
        for (int x : arr) {
            if (x <= max_val) {
                presence[x] = 1;
            }
        }
        
        // Iterate through the new array to find the k-th missing positive integer
        int missing_count = 0;
        for (int i = 1; i <= max_val; i++) {
            if (presence[i] == 0) {
                missing_count++;
            }
            if (missing_count == k) {
                return i;
            }
        }
        
        return max_val + (k - missing_count);  // In case the k-th missing number is beyond max_val
    }
};

