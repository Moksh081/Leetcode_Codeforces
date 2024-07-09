class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0){
                count++;
            }
        }
        vector<int> positive(count,0);
        vector<int> negative(nums.size()-count , 0);
        int j = 0;
        int k = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0){
                positive[j] = nums[i];
                j++;
            }else if(nums[i]<0){
                negative[k] = nums[i];
                k++;
            }
        }
         j = 0;
         k = 0;
        for(int i=0; i<nums.size();i++){
            if(i%2==0){
                nums[i] = positive[j];
                j++;
            }else{
                nums[i] = negative[k];
                k++;
            }
        }
      return nums;
    }
};
