class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, max_len = 1;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // left+1 to right-1 is the valid palindrome
            int len = right - left - 1;
            if (len > max_len) {
                start = left + 1;
                max_len = len;
            }
        };
        
        for (int i = 0; i < n; ++i) {
            expandAroundCenter(i, i);   // Odd length palindromes
            expandAroundCenter(i, i+1); // Even length palindromes
        }
        
        return s.substr(start, max_len);
    }
};

