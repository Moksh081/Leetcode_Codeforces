/*
class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    // Function to count words starting and ending with vowels in the range [l, r]
    int solve(int l, int r, vector<string>& words) {
        int count = 0;
        for (int i = l; i <= r; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                count++;
            }
        }
        return count;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int count = solve(l, r, words);
            ans.push_back(count);
        }
        return ans;
    }
};
*/

class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0); // Prefix sum array

        // Precompute the prefix sums
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefix[i + 1]++;
            }
        }

        // Process each query in constant time
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};

