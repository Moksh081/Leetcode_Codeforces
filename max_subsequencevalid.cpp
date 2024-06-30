class Solution {
public:
    int findoddsub(vector<int> &arr){
        int n = arr.size();
        int i = 0;
        int count_oddeven = 0;
        int count_evenodd = 0;
        
        // Count transitions starting with odd first
        int f = 1;
        while(i < n) {
            while(i < n && arr[i] == 0) i++;
            if (i < n && arr[i] % 2 == f) {
                count_oddeven++;
                f = 1 - f;
            }
            i++;
        }
        
        // Reset i and count transitions starting with even first
        i = 0;
        f = 0;
        while(i < n) {
            while(i < n && arr[i] != 0) i++;
            if (i < n && arr[i] % 2 == f) {
                count_evenodd++;
                f = 1 - f;
            }
            i++;
        }
        
        return max(count_oddeven, count_evenodd);
    }
    
    int findevensub(vector<int>& arr){
        int n = arr.size();
        int count_even = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 == 0){
                count_even++;
            }
        }
        return max(count_even, (n - count_even));
    }
    
    int maximumLength(vector<int>& arr) {
        int even = findevensub(arr);
        int odd = findoddsub(arr);
        return max(even, odd);
    }
};

