class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;
        
        // Traverse through the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // Push opening parentheses onto the stack
                st.push(s[i]);
            } else if (s[i] == ')') {
                // If it's a closing parenthesis
                if (!st.empty() && st.top() == '(') {
                    // If there's a matching opening parenthesis, pop it
                    st.pop();
                } else {
                    // Otherwise, this is an unmatched closing parenthesis
                    count++;
                }
            }
        }
        
        // Add any unmatched opening parentheses in the stack to the count
        count += st.size();
        
        return count;
    }
};

