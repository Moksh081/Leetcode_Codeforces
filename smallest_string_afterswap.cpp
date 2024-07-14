class Solution {
public:
    string getSmallestString(string s) {
        string result = s;
        for (int i = 0; i < s.size() - 1; ++i) {
            if ((s[i] % 2 == 0 && s[i + 1] % 2 == 0) || (s[i] % 2 != 0 && s[i + 1] % 2 != 0)) {
                swap(s[i], s[i + 1]);
                if (s < result) {
                    result = s;
                }
                // Swap back to restore original order for the next iteration
                swap(s[i], s[i + 1]);
            }
        }
        return result;
    }
};

