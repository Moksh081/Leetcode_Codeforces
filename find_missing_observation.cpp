class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        for (int i = 0; i < m; i++) {
            sum -= rolls[i];
        }
        if (sum < n || sum > 6 * n) {
            return {};
        }
        int avg = sum / n;
        int rem = sum % n;
    
        vector<int> res(n, avg);
    
        for (int i = 0; i < n && rem > 0; i++) {
            res[i]++;
            rem--;
        }
        
        return res;
    }
};
