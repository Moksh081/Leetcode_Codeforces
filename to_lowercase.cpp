#include<bits/stdc++.h>
class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+32;
            }
        }
        return s;
    }
};

/*
class Solution {
public:
    std::string toLowerCase(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower); 
        return s;
    }
};
*/
