class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                count += i;  // increment the operation count by the factor i
                n /= i;      // reduce n by dividing by the factor i
            }
        }
        return count;
    }
};

