class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;
        int count = 0;
        int max_count = 0;
        for(int i=0; i<n;i++){
            if(s[i]=='('){
                st.push('(');
                count++;
                max_count = max(count , max_count);
            }else if(s[i]== ')'){
                st.pop();
                count--;
            }
        }
        return max_count;
    }
};
