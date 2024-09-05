#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int>& height, vector<int>& dp){
	if(ind==0){
		return 0;
	}
	if(dp[ind]!=-1){
		return dp[ind];
	}
	int left = solve(ind-1,height,dp) + abs(height[ind]-height[ind-1]);
	int right = INT_MAX;
	if(ind>1){
		right = solve(ind-2,height,dp) + abs(height[ind]-height[ind-2]);
	}
	dp[ind] = min(left,right);
	return dp[ind];
}
int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};  // Explicitly initialize height vector with parentheses
    int n = height.size();
    vector<int> dp(n, -1);  // Initialize dp vector with -1

    cout << solve(n - 1, height, dp);  // Call solve for the last stone and print the result
    return 0;
}
