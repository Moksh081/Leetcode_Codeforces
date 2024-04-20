class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==""){
            return true;
        }
     stack<char> st;
     for(int i=s.length()-1;i>=0;i--){
         st.push(s[i]);
     }   
     for(int i=0;i<t.length();i++){
         if(!st.empty() && st.top()==t[i]){
             st.pop();
         }
     }
     if(!st.empty()){
         return false;
     }
     return true;
    }
};
