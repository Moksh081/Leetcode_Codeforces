class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        int n = word.size();
        std::stack<char> st;
        int count = 0;
        for(int k=0; k<n;k++){
            if(word[k]==ch){
                count++;
            }
        }
        if (count == 0){
            return word;
        }else{
        int i = 0;
        while (word[i] != ch && i < n) {
            st.push(word[i]);
            i++;
        }
        st.push(word[i]);
        i++;
        std::string reversed_prefix = "";
        while (!st.empty()) {
            reversed_prefix += st.top();
            st.pop();
        }
        for (int j = i; j < n; j++) {
            reversed_prefix += word[j];
        }
        return reversed_prefix;
        }
    }
};
