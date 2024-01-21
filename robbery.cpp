//robbery in alternate houses but max money
The recurrence relation is
 dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]), 
 meaning the maximum amount at the current house is the maximum of the amount robbed from the previous house or the amount robbed two houses ago plus the current house's money.
cpp
