#include <bits/stdc++.h>
using namespace std;


int minFrogJump(int n,int k,vector<int> &dp,int arr[])
{
    if(n==0) return dp[n]=0;
    if(dp[n]!=-1) return dp[n];
    
    int temp = INT_MAX;
    for(int i=n-1;i>=max(n-k,0);--i)
    {
        temp = min(temp,minFrogJump(i,k,dp,arr)+abs(arr[i]-arr[n]));
    }
    return dp[n] = temp;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> dp(n,-1);
    int arr[n];
    for (int i = 0; i < n; i++)cin>>arr[i];
    
    cout<<minFrogJump(n-1,k,dp,arr)<<endl;
    // for(int i:dp) cout<<i<<endl;
    return 0;
}
