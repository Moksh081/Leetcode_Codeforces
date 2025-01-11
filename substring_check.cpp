class Solution {
public:
    bool helper(string& w, string& d) {
        return w.find(d) != string::npos;  // Check if d is a substring of w
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> word;
        unordered_set<string> seen;  // To avoid duplicates

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && helper(words[i], words[j])) {
                    seen.insert(words[j]);  // Insert into set to avoid duplicates
                }
            }
        }

        word.assign(seen.begin(), seen.end());  // Convert set to vector
        return word;
    }
};

