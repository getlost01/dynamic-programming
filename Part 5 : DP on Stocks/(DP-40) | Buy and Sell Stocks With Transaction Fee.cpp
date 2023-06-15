class Solution {
public:
    int check(vector<int> &p, int i ,int n, bool canBuy, vector<vector<int>>& dp,int fee){
        if(i >= n)
            return 0;
        if(dp[i][(int)canBuy]!=-1)
            return dp[i][(int)canBuy];
        if(canBuy)
            return dp[i][(int)canBuy] = max(check(p,i+1,n,0,dp,fee)-p[i], check(p,i+1,n,1,dp,fee));
        
        return dp[i][(int)canBuy] = max(check(p,i+1,n,1,dp,fee)+p[i]-fee,check(p,i+1,n,0,dp,fee));

    }
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return check(p,0,n,1,dp,fee);
    }
};