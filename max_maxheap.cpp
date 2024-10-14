/*
class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long score = 0;
        sort(nums.begin(), nums.end());
        while (k--) {
            score += nums.back();
            if (nums.back() == 1) {
                score += k;  
                break;
            }
            int newElement = ceil(nums.back() / 3.0);
            nums.pop_back();
            auto it = upper_bound(nums.begin(), nums.end(), newElement);
            nums.insert(it, newElement);
        }
        return score;
    }
};
*/
#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long score = 0;

        // Create a max-heap (priority queue)
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());

        // Main loop to perform k operations
        while (k--) {
            // Get the largest element
            int maxElement = maxHeap.top();
            maxHeap.pop();

            // Add the largest element to the score
            score += maxElement;

            // If the largest element is 1, all subsequent elements will remain 1
            if (maxElement == 1) {
                // Add the remaining k to the score, because further operations would all add 1
                score += k;  // k operations left
                break;  // No more operations needed
            }

            // Calculate the new element and push it back into the max-heap
            int newElement = std::ceil(maxElement / 3.0);
            maxHeap.push(newElement);
        }

        return score;
    }
};

