class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalSum = 0;
        for (int val : chalk) {
            totalSum += val;
        }
        
        k %= totalSum;
        
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        
        return 0;  // In theory, this line is never reached.
    }
};

