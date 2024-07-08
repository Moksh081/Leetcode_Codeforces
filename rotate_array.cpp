class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is greater than the size of the array
        vector<int> arr(n, 0);
        int j = 0;
        
        for(int i = n - k; i < n; i++) {
            arr[j] = nums[i];
            j++;
        }
        for(int i = 0; i < n - k; i++) {
            arr[j] = nums[i];
            j++;
        }
        
        // Copy the elements from arr back to nums
        for(int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};

