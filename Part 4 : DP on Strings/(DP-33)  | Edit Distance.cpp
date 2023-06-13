class Solution {
public:
    int minDistance(string str1, string str2) {
            int n = str1.size();
            int m = str2.size();
            int dp[n+1][m+1];
            for(int i = 0; i<=n ;++i)
                dp[i][0] = i;
            for(int i = 0; i<=m; ++i)
                dp[0][i] = i;
            
            for(int i = 1;i<=n;++i){
                for(int j = 1; j<=m;++j){
                    if(str1[i-1] == str2[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                        dp[i][j] = min(dp[i][j-1],dp[i][j]);
                        dp[i][j] = min(dp[i-1][j-1],dp[i][j]);
                        ++dp[i][j];
                    }
                    // cout<<dp[i][j]<<" ";
                }
                // cout<<endl;
            }
            return dp[n][m];
            }
};