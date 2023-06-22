class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n);
        for(int i = 1;i<=n;++i){
            dp[i-1] = vector<int>(i,INT_MAX);
        }
        dp[0][0] = t[0][0];
        for(int i = 0;i<n-1;++i){
            for(int j = 0;j<=i;++j){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]+t[i+1][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+t[i+1][j+1]);
            }
        }
        int nx = INT_MAX;
        for(auto i: dp[n-1]){
           nx = min(nx,i);
        }
        return nx;
    }
};