#include <bits/stdc++.h> 
int check(int i ,int j,  vector<int>& arr, vector<vector<int>>& dp){
	if(i>j)	return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int out = 0;
	for(int k = i; k<=j;++k){
		out = max(out, check(i,k-1,arr,dp)+check(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j+1]);
	}

	return dp[i][j] = out;
}
int maxCoins(vector<int>& a)
{
	int n = a.size();
	vector<int> arr(n+2);
	arr[0] = arr[n+1] = 1;
	for(int i = 0; i<n;++i) arr[i+1] = a[i];
	vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
	return check(1,n,arr,dp);
}