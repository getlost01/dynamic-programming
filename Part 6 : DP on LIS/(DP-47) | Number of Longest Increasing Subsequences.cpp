#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    
    int nax = 1;
    
    for(int i=0; i<=n-1; i++){
        for(int j = 0; j <=i-1; j++){
            
            if(arr[j]<arr[i] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
                cnt[i] = cnt[j];
            }
            else if(arr[j]<arr[i] && dp[j]+1==dp[i]){
                cnt[i] = cnt[i] + cnt[j];
            }
        }
         nax = max(nax,dp[i]);
    }
    
    int c =0;
    
    for(int i=0; i<=n-1; i++){
       if(dp[i]==nax) c+=cnt[i];
    }
    
    return c;
}