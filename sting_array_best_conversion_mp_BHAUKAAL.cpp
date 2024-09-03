class Solution {
public:
    int getLucky(string s, int k) {
        unordered_map<char, int> mp;

        // Populate the map with a = 1, b = 2, ..., z = 26
        for (char c = 'a'; c <= 'z'; ++c) {
            mp[c] = c - 'a' + 1;
        }

        string numStr = "";
        for (int i = 0; i < s.size(); i++) {
            numStr += to_string(mp[s[i]]);
        }

        while (k--) {
            int sum = 0;
            for (char c : numStr) {
                sum += c - '0'; 
            }
            numStr = to_string(sum); 
        }

        return stoi(numStr); 
    }
};
