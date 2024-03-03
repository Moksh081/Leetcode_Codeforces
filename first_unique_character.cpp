class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        
        // Count occurrences of each character
        for(char c : s) {
            count[c]++;
        }
        
        // Find the index of the first non-repeating character
        for(int i = 0; i < s.size(); i++) {
            if(count[s[i]] == 1) {
                return i;
            }
        }
        
        // If no non-repeating character found, return -1
        return -1;
    }
};
