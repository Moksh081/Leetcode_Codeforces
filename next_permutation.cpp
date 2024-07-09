class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // finding element where change is happening
        int idx = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
// if idx is still = -1, means it is already in maximum possible state, so we just have to reverse the number or array
        if(idx==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
// algorithm for finding next permutation
        else{
// step 1: reverse the right side of you array
            reverse(nums.begin()+idx+1, nums.end());

// step 2: find just greater number after nums[idx]
            int j = -1;
        for(int i=idx+1; i<n; i++){
            if(nums[idx]<nums[i]){
                j = i;
                break;
            }
        }
        // swapping
        int temp = nums[idx];
        nums[idx]= nums[j];
        nums[j]=temp;
        return;
        }
        
    }
};
