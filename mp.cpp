class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        int count = 0;

        // Insert all allowed characters into the map
        for (int i = 0; i < allowed.size(); i++) {
            mp[allowed[i]] = 1;
        }

        // Check each word in the words vector
        for (int i = 0; i < words.size(); i++) {
            bool isConsistent = true;  // Assume the word is consistent
            for (int j = 0; j < words[i].size(); j++) {
                if (mp.find(words[i][j]) == mp.end()) {  // If the character is not in the map
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                count++;
            }
        }

        return count;
    }
};

