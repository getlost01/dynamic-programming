#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> dp(n,0);
    int arr[n];
    for (int i = 0; i < n; i++)cin>>arr[i];
    dp[1] = abs(arr[1] - arr[0]); 
  	for(int i = 2;i<n;++i){
    	dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
  	cout<<dp[n-1]<<endl;
    return 0;
}