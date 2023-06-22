#include <bits/stdc++.h> 
int check(int i, int w, vector<int> &p, vector<int> &wt,vector<vector<int>>& dp){
    if(i == 0){
        return (w/wt[i])*p[i];
    }

    if(dp[i][w] != -1)
        return dp[i][w];

    int ntake = check(i-1,w,p,wt,dp);
    int take = 0;
    if(w>=wt[i])
        take = check(i,w-wt[i],p,wt,dp) + p[i];
    
    return dp[i][w] = max(take,ntake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return check(n-1,w,profit,weight,dp);
}
