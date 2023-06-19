#include <bits/stdc++.h> 
int check(vector<int>& arr, int i, int last,int state,vector<vector<map<int,int>>>& dp){
	if( i == -1)
		return 0;

	if(dp[i][state].find(last) != dp[i][state].end())
		return dp[i][state][last];
		
	if(arr[i] < last && state == 1)
		return dp[i][state][last] = max(1 + check(arr,i-1,arr[i],state,dp), check(arr,i-1,last,state,dp));
	if(arr[i] < last && state == 0)
		return dp[i][state][last] = max(1 + check(arr,i-1,arr[i],1,dp), check(arr,i-1,last,state,dp));
	if(arr[i] > last && state == 0)
		return dp[i][state][last] = max(1 + check(arr,i-1,arr[i],state,dp), check(arr,i-1,last,state,dp));
	
	return dp[i][state][last] = check(arr,i-1,last,state,dp);
}
int longestBitonicSequence(vector<int>& arr, int n) {
	  vector<vector<map<int,int>>> dp(n,vector<map<int,int>>(2));
	  return check(arr,n-1,-1,0,dp);  
} 
