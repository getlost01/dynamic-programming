#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int  i = N-1; i>=0;--i){
        for(int j = i+2; j<N;++j){
            int sum = INT_MAX;
            for(int k = i+1; k<j; ++k){
                sum = min(sum, arr[i]*arr[k]*arr[j] +  dp[i][k] + dp[k][j]);
            }
            dp[i][j] = sum;
        }
    }

    return dp[0][N-1];
}