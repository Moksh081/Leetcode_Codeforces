class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string result;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++; // Skip leading spaces
            }
            if (i >= s.size()) break;
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            string word = s.substr(i, j - i);
            stk.push(word);
            i = j; // Move to the next word
        }
        
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
            if (!stk.empty()) {
                result += ' ';
            }
        }
        return result;
    }
};

