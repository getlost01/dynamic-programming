class Solution {
public:
    int check(int i,vector<int>& arr,int k, int n, int kt, vector<int>& dp){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int nax = arr[i],out = arr[i];
        for(int p = 0;p<k;++p){
            if(i+p >= n) break;

            nax = max(nax,arr[i+p]);
            out = max(out, (p+1)*nax + check(i+p+1,arr,k,n,kt+1,dp));
        }
        return dp[i] = out;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return check(0,arr,k,n,1,dp);
    }
};