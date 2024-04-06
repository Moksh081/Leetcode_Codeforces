class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    s[i] = '*'; // Mark for deletion
                } else {
                    st.pop();
                }
            }
        }

        while (!st.empty()) {
            s[st.top()] = '*'; // Mark unmatched '(' for deletion
            st.pop();
        }

        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                result += s[i];
            }
        }

        return result;
    }
};
