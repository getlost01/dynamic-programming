#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    if(n == 1) return nums[0];
    vector<int> dp(n+1,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int j = 2; j<n;++j){
        dp[j] = max(dp[j-1],dp[j-2]+nums[j]);
    }
    return dp[n-1];
}