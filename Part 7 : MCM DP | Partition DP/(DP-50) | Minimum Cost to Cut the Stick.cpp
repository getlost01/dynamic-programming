#include <bits/stdc++.h> 
int check(int i, int j, vector<int> &cuts, vector<vector<int>>& dp){
    if(i+1 >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int out = INT_MAX;
    for(int k = i+1; k<j; ++k){
        out = min(out, check(i,k,cuts,dp) + check(k,j,cuts,dp));
    }

    return dp[i][j] = out + (cuts[j] - cuts[i]);
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return check(0,cuts.size()-1,cuts,dp);
}