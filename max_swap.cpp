class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num); // Convert integer to string
        int n = numStr.size();
        int maxIdx = n - 1;
        int leftIdx = -1, rightIdx = -1;

        // Iterate from right to left to find the largest digit and its index
        for (int i = n - 2; i >= 0; i--) {
            if (numStr[i] < numStr[maxIdx]) {
                leftIdx = i;  // Left index for the swap
                rightIdx = maxIdx;  // Right index for the swap
            } else if (numStr[i] > numStr[maxIdx]) {
                maxIdx = i;  // Update the largest digit's index
            }
        }

        // If a swap is needed, swap the digits
        if (leftIdx != -1) {
            swap(numStr[leftIdx], numStr[rightIdx]);
        }

        // Convert the modified string back to an integer and return
        return stoi(numStr);
    }
};

