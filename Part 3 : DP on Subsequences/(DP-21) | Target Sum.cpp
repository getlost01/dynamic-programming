#include <bits/stdc++.h> 

    
    int check(int target,vector<int>& arr,int n, int i,int sum,vector<vector<int>>& dp,int sz){
        if(i >= n){
            return (int)(target == sum);
        }
        if(dp[i][sz + sum] > -1){
            return dp[i][sz + sum];
        }

        int out = check(target,arr,n,i+1,sum+arr[i],dp,sz);
        out += check(target,arr,n,i+1,sum-arr[i],dp,sz);
        dp[i][sz + sum] = out;
        return out;
    }
    int targetSum(int n, int target, vector<int>& arr) {
        int sz = 0;
        for(auto i: arr)
            sz += i;
        vector<vector<int>> dp(arr.size(),vector<int>(2*sz+10,-1));
        return check(target,arr,arr.size(),0,0,dp,sz);
    }
