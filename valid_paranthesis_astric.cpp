class Solution {
public:
/*
    bool checkValidString(string s) {
        stack<int> leftStack;
        stack<int> starStack;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                leftStack.push(i);
            } else if(s[i] == '*') {
                starStack.push(i);
            } else { // s[i] == ')'
                if(!leftStack.empty()) {
                    leftStack.pop();
                } else if(!starStack.empty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }
        
        while(!leftStack.empty() && !starStack.empty()) {
            if(leftStack.top() > starStack.top()) {
                return false;
            }
            leftStack.pop();
            starStack.pop();
        }
        
        return leftStack.empty();     
    }
*/
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;
        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin = max(cmin - 1, 0);
            } else if (c == '*') {
                cmax++;
                cmin = max(cmin - 1, 0);
            }
            if (cmax < 0) {
                return false;
            }
        }
        return cmin == 0;
    }

};
