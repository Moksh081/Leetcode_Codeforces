/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Initialize frequency map
        unordered_map<int, int> frequency;
        
        // Count occurrences of each element
        for (int num : nums) {
            frequency[num]++;
        }
        
        // Find the element with a single occurrence
        for (const auto& entry : frequency) {
            if (entry.second == 1) {
                return entry.first;
            }
        }
        
        // If no single element is found (should not happen per problem constraints)
        return -1;
    }
};

*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}
};

