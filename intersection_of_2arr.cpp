/*class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int>result;
        unordered_map<int,int>mp;
        for(auto &num : nums1){
            mp[num]++;
        }
        for(auto & num : nums2){
            if(mp.find(num) != mp.end()){
                result.push_back(num);
                mp.erase(num);
            }
        }
        return result;
    }
};*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                    i++;
                j++;
            } else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return ans;
    }
};
