#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isvalid(vector<char> &curr){
        stack<char> stk;
        int n = curr.size();
        for(int i = 0; i < n; i++){
            if(curr[i] == '('){
                stk.push(curr[i]);
            } else if(curr[i] == ')'){
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

    void fn(vector<char> &curr, int n, vector<string> &result){
        if(curr.size() == 2 * n){
            if(isvalid(curr)){
                result.push_back(string(curr.begin(), curr.end()));
            }
            return;
        }
        curr.push_back('(');
        fn(curr, n, result);
        curr.pop_back();
        curr.push_back(')');
        fn(curr, n, result);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<char> curr;
        fn(curr, n, result);
        return result;
    }
};

