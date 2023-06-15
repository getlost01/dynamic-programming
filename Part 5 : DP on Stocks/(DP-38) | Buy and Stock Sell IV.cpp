class Solution {
public:
    int maxProfit(int t, vector<int>& p) {
        int n = p.size();
        int dp[n+1][2][t+1];
        for(int i = 0;i<2;++i){
            for(int j = 0; j<t+1; ++j){
                dp[n][i][j] = 0;
            }
        }
        for(int i = 0;i<n;++i){
            for(int j = 0; j<2; ++j){
                dp[i][j][0] = 0;
            }
        }
        for(int i = n-1;i>=0;--i){
            for(int j = 1; j>=0;--j){
                for(int k=t; k>0; --k){
                    if(j)
                    dp[i][j][k] = max(dp[i+1][0][k] - p[i],dp[i+1][1][k]);
                    else
                    dp[i][j][k] = max(dp[i+1][1][k-1] + p[i], dp[i+1][0][k]);
                    // cout<<dp[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
        return dp[0][1][t];
    }
};