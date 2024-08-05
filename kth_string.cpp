class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        
        // Count the frequency of each string
        for(const auto &it: arr){
            mp[it]++;             
        }

        // Iterate over the array to find the k-th distinct string
        for(const auto &it: arr){
            if(mp[it] == 1) {
                k--;
                if(k == 0) {
                    return it;
                }
            }
        }

        // If there is no k-th distinct string, return an empty string
        return "";
    }
};
s
