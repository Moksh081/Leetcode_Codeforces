class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false; // Negative numbers and 0 cannot be powers of 4
        }
        
        double logarithm = log(n) / log(4); // Calculate logarithm base 4 of n
        
        // Check if the result is an integer
        return (logarithm - (int)logarithm) == 0;
    }
};
