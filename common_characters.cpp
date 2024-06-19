class Solution {
public:
    void fill(const string& word, int count[26]) {
        for (char ch : word) {
            count[ch - 'a']++;
        }
    }

    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        int count[26];
        memset(count, INT_MAX, sizeof(count));  // Initialize count array with INT_MAX

        // Fill count array with the character frequencies of the first word
        int temp[26] = {0};
        fill(words[0], temp);
        memcpy(count, temp, sizeof(temp));

        // Update count array with minimum frequencies across all words
        for (int i = 1; i < n; ++i) {
            memset(temp, 0, sizeof(temp));
            fill(words[i], temp);
            for (int j = 0; j < 26; ++j) {
                count[j] = min(count[j], temp[j]);
            }
        }

        // Collect the result based on the count array
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (count[i]-- > 0) {
                result.push_back(string(1, i + 'a'));
            }
        }

        return result;
    }
};

