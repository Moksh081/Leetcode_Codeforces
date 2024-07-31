class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        
        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check if the next character is '-' or '+'
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign <= INT_MIN) {
                return INT_MIN;
            } else if (ans * sign >= INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        
        return ans * sign;
    }
};

