//climb staircase
class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int dp[n+1];//make array to store n+1 ways for n+1 steps ie 1 to n+1
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]; //ways
        }
        return dp[n];
    }
};
