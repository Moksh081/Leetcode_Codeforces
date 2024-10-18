class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, -1);  // Initialize the vector with size n and default value -1
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller or equal to the current element
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Only update the result if we're in the first pass (i < n)
            if(i < n) {
                if(!st.empty()) {
                    a[i] = st.top();  // Next greater element found
                }
            }

            // Push the current element to the stack
            st.push(nums[i % n]);
        }

        return a;
    }
};

