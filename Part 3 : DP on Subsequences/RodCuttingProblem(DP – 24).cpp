int cutRod(vector<int> &price, int n)
{
	int dp[n][n+1];
	for(int i=0;i<=n;++i)
		dp[0][i] = i*price[0];
	
	for(int i = 1; i<n;++i){
		for(int rs = 0; rs<=n;++rs){
			int ntake = dp[i-1][rs];
			int take = 0;
			if(rs>=i+1)
				take = dp[i][rs - i - 1] + price[i];
			
			dp[i][rs] = max(take,ntake);
		}
	}

	return dp[n-1][n];
}

