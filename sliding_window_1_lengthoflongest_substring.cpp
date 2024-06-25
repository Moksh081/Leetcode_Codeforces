class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1); // Use vector instead of array
        int left = 0, right = 0;
        int n = s.size();
        int maxlen = 0;
        
        while (right < n) {
            if (mpp[s[right]] != -1)
                if(mpp[s[right]] >= left) 
                    left = mpp[s[right]] + 1;
            
            
            int len = right - left + 1; // Calculate length of current substring
            maxlen = max(maxlen, len); // Update maximum length if needed
            
            mpp[s[right]] = right; // Update the index of current character
            
            right++; // Expand the window to the right
        }
        
        return maxlen;
    }
};

