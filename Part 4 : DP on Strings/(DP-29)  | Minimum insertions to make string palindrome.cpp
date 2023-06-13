    #include <bits/stdc++.h> 
    int check(string& s, string& t, int i,int j,vector<vector<int>>& dp){
        if(i == 0 || j == 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i-1] == t[j-1])
            return dp[i][j] = 1 + check(s,t,i-1,j-1,dp);
        
        return dp[i][j] = max(check(s,t,i-1,j,dp),check(s,t,i,j-1,dp));
    }
    int minInsertion(string &s)
    {
        string t = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return s.size() - check(s,t,n,n,dp);
    }