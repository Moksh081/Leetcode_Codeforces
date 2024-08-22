#include <iostream>
#include <vector>
using namespace std;

void fn(vector<int> &ds, int ind, int arr[], int n) {
    if (ind >= n) {
        for (int i = 0; i < ds.size(); i++) {
            cout << ds[i] << " ";
        }
        if (ds.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    fn(ds, ind + 1, arr, n);  // Corrected semicolon to a comma
    ds.pop_back();
    fn(ds, ind + 1, arr, n);  // Corrected semicolon to a comma
}

int main() {
    int arr[] = {3, 2, 1};
    int n = 3;
    vector<int> ds;
    fn(ds, 0, arr, n);
    return 0;
}

/*
class Solution {
    private:
    void solve(vector<int> nums , vector<vector<int>> &ans , vector<int> &output , int start){
          ans.push_back(output);
          for(int i=start;i<nums.size();++i){
            output.push_back(nums[i]);
            solve(nums,ans,output,i+1);
            output.pop_back();
          }
 }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans ,output,0);
           return ans;
    }
};
*/
