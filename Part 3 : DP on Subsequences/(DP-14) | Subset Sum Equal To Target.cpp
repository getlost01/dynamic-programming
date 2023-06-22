#include <bits/stdc++.h> 
bool check(int n, int k, vector<int> &arr,int sum, int i,vector<vector<int>>& dp){
    if(sum == k) return true;
    if(sum > k ) return false;
    if(i == n ) return false;
    if(dp[i][sum]!=-1) return (bool)dp[i][sum];

    bool take = check(n,k,arr,sum,i+1,dp);
    bool nottake = check(n,k,arr,sum+arr[i],i+1,dp);

    dp[i][sum] = take|nottake;
    return dp[i][sum];

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return check(n,k,arr,0,0,dp);
}