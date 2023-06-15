#include "vector"
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp;
    dp.push_back(arr[0]);
    for(int i = 1;i<n;++i){
        if(arr[i]>dp.back())
            dp.push_back(arr[i]);
        else{
            auto it = lower_bound(dp.begin(),dp.end(),arr[i]) - dp.begin();
            dp[it] = arr[i];
        }
    }

    return dp.size();
}