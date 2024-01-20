class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = 0; // Index for nums1
        int j = 0; // Index for nums2
        int k = 0; // Index for the merged array

        std::vector<int> arr(m + n);

        // Merge from the start of the arrays
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr[k++] = nums1[i++];
            } else {
                arr[k++] = nums2[j++];
            }
        }

        // If there are remaining elements in nums1, copy them to arr
        while (i < m) {
            arr[k++] = nums1[i++];
        }

        // If there are remaining elements in nums2, copy them to arr
        while (j < n) {
            arr[k++] = nums2[j++];
        }

        // Copy the merged array back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = arr[i];
        }
    }
};

