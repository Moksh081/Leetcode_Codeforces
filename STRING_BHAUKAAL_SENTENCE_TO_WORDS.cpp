class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string word;
        stringstream ss1(s1), ss2(s2);
        
        // Add words from the first sentence
        while (ss1 >> word) {
            mp[word]++;
        }
        
        // Add words from the second sentence
        while (ss2 >> word) {
            mp[word]++;
        }
        
        vector<string> res;
        // Collect words that appear exactly once
        for (auto it : mp) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }
        
        return res;
    }
};

