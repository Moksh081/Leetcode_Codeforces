class Solution {
public:
    int beautySum(string s) {
        int totalBeautySum = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freqMap; // Frequency map for each starting position
            for (int j = i; j < n; ++j) {
                freqMap[s[j]]++; // Increment frequency of the current character
                
                // Find max and min frequency in the current substring
                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                for (auto &p : freqMap) {
                    maxFreq = max(maxFreq, p.second);
                    minFreq = min(minFreq, p.second);
                }
                
                totalBeautySum += (maxFreq - minFreq); // Add beauty of current substring
            }
        }
        
        return totalBeautySum;
    }
};

