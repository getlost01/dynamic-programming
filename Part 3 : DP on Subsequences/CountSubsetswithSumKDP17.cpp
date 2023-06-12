#include <bits/stdc++.h> 
int findWays(vector<int> &arr, int k){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    for(int i = 0; i<n;++i) dp[i][0] = 1;
    if(arr[0]<=k)
    dp[0][arr[0]] = 1;
    for(int i = 1;i<n;++i){
        for(int tar = 0;tar<=k;++tar){
            int nottake = dp[i-1][tar];
            int take = 0;
            if(tar == arr[i])
                ++take;
            if(tar > arr[i])
                take = dp[i-1][tar - arr[i]];
            dp[i][tar] = take+nottake;
        }
    }
    return dp[n-1][k];
}