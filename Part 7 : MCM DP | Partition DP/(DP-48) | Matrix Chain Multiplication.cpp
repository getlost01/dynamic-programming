#include <bits/stdc++.h> 
int check(int i, int j, vector<int> &arr, vector<vector<int>>& dp ){
    if(i+1 >= j)
    return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int sum = INT_MAX;
    for(int k = i+1; k<j; ++k){
        sum = min(sum, arr[i]*arr[k]*arr[j] +  check(i,k,arr,dp) + check(k,j,arr,dp));
    }
    return dp[i][j] = sum;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return check(0,N-1,arr, dp);
}