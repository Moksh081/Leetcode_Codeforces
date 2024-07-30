class Solution {
public:
    string largestOddNumber(string num) {
        int max_index = -1;
        for (int i = 0; i < num.size(); i++) {
            if ((num[i] - '0') % 2 != 0) {
                max_index = i;
            }
        }
        if (max_index == -1) {
            return "";
        } else {
            return num.substr(0, max_index + 1);
        }
    }
};

