#include <bits/stdc++.h>
using namespace std;

//overlapping sub problems
//memorization

int fibo(int n,vector<int> &dp)
{
    if(n<=1) return dp[n]=n;
    
    if(dp[n]!=-1) return dp[n];

    return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    fibo(n,dp);
    for(int i: dp) cout<<i<<" ";
    return 0;
}

// Reccursion Tabulation Method (Bottom Up)
// Time Complexity = O(n)
// Memory Complexity = O(n)