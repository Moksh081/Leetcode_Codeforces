  //brute force : runtime error 
/*
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int k = 1;  
        int mod = (int)(1e9+7);
        while (k <= n) { 
            for (int i = 0; i <= n - k; i++) {
                int minVal = arr[i];
                for (int j = i; j < i + k; j++) {
                    minVal = min(minVal, arr[j]);
                }
                sum = (sum + minVal)%mod;
            }
            k++;  
        }
        return sum;
    }
};
*/

//optimal : 

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Calculate the distance to the previous smaller element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        // Clear the stack to reuse it for the next calculation
        while (!s.empty()) {
            s.pop();
        }

        // Calculate the distance to the next smaller element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        // Calculate the result using the left and right arrays
        int result = 0;
        for (int i = 0; i < n; ++i) {
            long long contribution = (long long) arr[i] * left[i] * right[i];
            result = (result + contribution) % MOD;
        }
        
        return result;
    }
};

