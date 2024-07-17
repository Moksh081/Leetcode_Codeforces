#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        /*

        TIME LIMIT EXCEDED

        set<vector<int>> st;
       int n = arr.size();
        // Check all possible triplets:
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp); // Use insert instead of push_back
                    }
                }
            }
        }

        // Store the set elements in the answer:
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        */


        ////////// METHOD 2 : TIME LIMIT EXCEDED

        /*
        set<vector<int>> st;
        int n = arr.size();
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    */

   vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
    }
};

