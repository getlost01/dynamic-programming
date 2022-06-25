#include <bits/stdc++.h>
using namespace std;


int minFrogJump(int n,vector<int> &dp,int arr[])
{
    if(n==0) return dp[n]=n;
    if(n==1) return dp[n]=abs(arr[1]-arr[0]);
    if(dp[n]!=-1) return dp[n];
    return dp[n] = min(minFrogJump(n-1,dp,arr)+abs(arr[n-1]-arr[n]),minFrogJump(n-2,dp,arr)+abs(arr[n-2]-arr[n]));
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n,-1);
    int arr[n];
    for (int i = 0; i < n; i++)cin>>arr[i];
    
    cout<<minFrogJump(n-1,dp,arr)<<endl;
    // for(int i:dp) cout<<i<<endl;
    return 0;
}
