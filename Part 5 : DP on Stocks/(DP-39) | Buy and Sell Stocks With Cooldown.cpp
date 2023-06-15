#include <bits/stdc++.h>
int nin = INT_MIN;
int check(vector<int> &p, int i, int n,int canBuy,int cool,vector<vector<vector<int>>>& dp){
    if(i == n){
        return 0;
    }

    if(dp[i][canBuy][cool] != nin)
        return dp[i][canBuy][cool];

    if(canBuy){
        if(cool)
            return dp[i][canBuy][cool] = check(p,i+1,n,1,0,dp);
        return dp[i][canBuy][cool] = max(check(p,i+1,n,0,0,dp)-p[i],check(p,i+1,n,1,0,dp));
    }
    
    return dp[i][canBuy][cool] = max(check(p,i+1,n,1,1,dp)+p[i],check(p,i+1,n,0,0,dp));
}
int stockProfit(vector<int> &p){
    vector<vector<vector<int>>> dp(p.size()+1,vector<vector<int>>(2,vector<int>(2,nin)));
    return check(p,0,p.size(),1,0,dp);
}