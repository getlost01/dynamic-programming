int ninjaTraining(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n,vector<int>(3,0));
    for(int i = 0;i<3;++i)
        dp[0][i] = p[0][i];
    for(int i = 1;i<n;++i){
        for(int j = 0 ;j<3;++j){
            int nx = -1;
            for(int k = 0;k<3;++k){
                if(k != j)
                    nx = max(nx,dp[i-1][k]);
            }
            dp[i][j] = p[i][j] + nx;
        }
    }
    int nx = -1;
    for(int k = 0;k<3;++k)
        nx = max(nx,dp[n-1][k]);
    return nx;
}