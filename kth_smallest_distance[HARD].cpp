class Solution {
    private int solve(int[] nums, int maxDis) {
        int count=0, j=0;
        for(int i=0;i<nums.length;i++) {
            while(j < nums.length && nums[j]-nums[i] <= maxDis) j++;
            count += j-i-1;
        }
        return count;
    }

    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int l=0, h=nums[n-1]-nums[0];

        while(l < h) {
            int mid = l + (h-l)/2;
            if(solve(nums, mid) < k) l = mid+1;
            else h = mid;
        }
        return l;
    }
}
