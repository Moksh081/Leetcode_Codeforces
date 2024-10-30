#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> st;

        for (char digit : num) {
            // Remove elements from the stack if they are larger than the current digit (and we still need to remove more digits)
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            // Avoid leading zeros by only pushing non-zero digits unless the stack is empty
            if (!st.empty() || digit != '0') {
                st.push(digit);
            }
        }

        // If there are still digits to remove, remove them from the end of the stack
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // Build the result string from the stack
        std::string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        std::reverse(result.begin(), result.end());

        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

