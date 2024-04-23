class Solution {
public:
    int countSegments(string s) {
        int k = 0;
        if (s.size() == 0) {
            return 0;
        }
        
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            
            if (i == s.size()) {
                break;
            }
            
            k++;
            
            while (i < s.size() && s[i] != ' ') {
                i++;
            }
        }
        
        return k;
    }
};

