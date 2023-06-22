long countWaysToMakeChange(int *d, int n, int value)
{
    long dp [n][value+1];
    for(int i = 0;i<=value;++i){
        dp[0][i] = (int)(i%d[0] == 0);
    }

    for(int i = 1 ;i<n;++i){
      for (int j = 0; j <= value; ++j) {
        long ntake = dp[i - 1][j];
        long take = 0;
        if (j >= d[i])
          take = dp[i][j - d[i]];

        dp[i][j] = take + ntake;
      }
    }

    return dp[n-1][value]; 
}