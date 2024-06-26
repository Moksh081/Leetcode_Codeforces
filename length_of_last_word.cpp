class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters until a space is encountered
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

