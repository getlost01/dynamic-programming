class Solution {
public:
    bool check(string& p, string& t, int i, int j,vector<vector<int>>& dp){
        if(i == 0 && j == 0)
            return true;
        if(i == 0)
            return false;
        if(j == 0){
            if(p[i-1] == '*')
            return check(p,t,i-1,j,dp);
            
            return false;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(p[i-1] == t[j-1] || p[i-1] == '?')
            return dp[i][j] = check(p,t,i-1,j-1,dp);
        if(p[i-1] == '*')
            return dp[i][j] = check(p,t,i,j-1,dp) || check(p,t,i-1,j-1,dp) || check(p,t,i-1,j,dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size()+1,vector<int>(s.size()+1,-1));
        return check(p,s,p.size(),s.size(),dp);
    }
};