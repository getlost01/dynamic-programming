class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        vector<vector<int>> dp = m;
        int n = m.size();
        for(int i = 1;i<n;++i){
            for(int j = 0;j<n;++j){
                dp[i][j] = dp[i-1][j];
                if(j-1>=0)
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                if(j+1<n)
                dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
                dp[i][j] += m[i][j];
            }
        }

        int out = INT_MAX;
        for(auto i: dp[n-1]) out = min(out,i);
        return out;
    }
};