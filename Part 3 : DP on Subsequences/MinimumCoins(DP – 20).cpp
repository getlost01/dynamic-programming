#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(num.size(),vector<int> (x+1));
    for (int i = 0; i <= x; ++i) {
      if (i % num[0] == 0)
        dp[0][i] = i / num[0];
      else
        dp[0][i] = 1e8;
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= x; ++j){
            int ntake = dp[i-1][j];
            int take = INT_MAX;
            if(num[i]<=j)
                take = 1 + dp[i][j - num[i]]; 
            dp[i][j] = min(take,ntake);
        }
    }
    return (dp[n-1][x]>=1e8)?-1:dp[n-1][x] ;
}