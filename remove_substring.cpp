#include <string>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        int sum = 0;
        
        auto erasePair = [&](char a, char b, int gain) {
            std::string result;
            for (char c : s) {
                if (!result.empty() && result.back() == a && c == b) {
                    result.pop_back();
                    sum += gain;
                } else {
                    result.push_back(c);
                }
            }
            s = result; // update s with the remaining string
        };
        
        if (x > y) {
            erasePair('a', 'b', x);
            erasePair('b', 'a', y);
        } else {
            erasePair('b', 'a', y);
            erasePair('a', 'b', x);
        }
        
        return sum;
    }
};

