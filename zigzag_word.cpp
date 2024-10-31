class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 
        
        vector<string> ans(numRows);
        int i = 0;
        
        while (i < s.length()) {
            for (int j = 0; j < numRows && i < s.length(); j++) {
                ans[j] += s[i++]; // Going down
            }
            for (int j = numRows - 2; j > 0 && i < s.length(); j--) {
                ans[j] += s[i++]; // Going up
            }
        }
        
        string res = "";
        for (const string& str : ans) {
            res += str;
        }
        
        return res;
    }
};
