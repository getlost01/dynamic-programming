#include <bits/stdc++.h>
using namespace std;


int DistinctWayToUpStair(int n,vector<int> &dp)
{
    if(n<=1) return dp[n]=n;
    
    if(dp[n]!=-1) return dp[n];

    return dp[n] = DistinctWayToUpStair(n-1,dp)+DistinctWayToUpStair(n-2,dp);
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<DistinctWayToUpStair(n,dp)<<endl;
    return 0;
}
