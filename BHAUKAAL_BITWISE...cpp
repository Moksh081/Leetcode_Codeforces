class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0] = -1; // Initialize for the case when the whole substring has even counts of vowels
        int cnt = 0, ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // Update the bitmask if a vowel is encountered
            if (s[i] == 'a') cnt ^= (1 << 0); 
            else if (s[i] == 'e') cnt ^= (1 << 1); 
            else if (s[i] == 'i') cnt ^= (1 << 2); 
            else if (s[i] == 'o') cnt ^= (1 << 3); 
            else if (s[i] == 'u') cnt ^= (1 << 4); 
            
            // Check if this bitmask was seen before
            if (mp.count(cnt)) {
                ans = max(ans, i - mp[cnt]);
            } else {
                mp[cnt] = i; // Store the first occurrence of this bitmask
            }
        }
        
        return ans;
    }
};

