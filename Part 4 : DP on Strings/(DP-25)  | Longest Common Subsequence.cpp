#include "vector"
int check(string s,string t, int i, int j,vector<vector<int>>& dp){
	if( i < 0 || j < 0){
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	if(s[i] == t[j])
		return dp[i][j] = 1 + check(s,t,i-1,j-1,dp);

	return dp[i][j] = max(check(s,t,i-1,j,dp),check(s,t,i,j-1,dp));
}
int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
	
	return check(s,t,s.size()-1,t.size()-1,dp);
}