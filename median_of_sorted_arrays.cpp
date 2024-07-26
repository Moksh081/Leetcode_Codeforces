class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int a = 0, b = 0;
        int i = 0, j = 0, count = 0;
        double median;
        
        if (n % 2 == 0) {
            int index1 = n / 2 - 1;
            int index2 = n / 2;
            while (i < n1 || j < n2) {
                int val;
                if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
                    val = nums1[i++];
                } else {
                    val = nums2[j++];
                }
                if (count == index1) a = val;
                if (count == index2) {
                    b = val;
                    break;
                }
                count++;
            }
            median = (a + b) / 2.0;
        } else {
            int index1 = n / 2;
            while (i < n1 || j < n2) {
                int val;
                if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
                    val = nums1[i++];
                } else {
                    val = nums2[j++];
                }
                if (count == index1) {
                    a = val;
                    break;
                }
                count++;
            }
            median = a;
        }
        return median;
    }
};

