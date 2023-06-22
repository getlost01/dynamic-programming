#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> dp(n,INT_MAX);
    int arr[n];
    for (int i = 0; i < n; i++)cin>>arr[i];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]); 
  	for(int i = 2;i<n;++i){
      	for(int j = 1;j<=k;++j){
         	if(i - j >= 0){
            	dp[i] = min(dp[i-j]+abs(arr[i]-arr[i-j]),dp[i]);
            }
          	else
              break;
        }
    }
  	cout<<dp[n-1]<<endl;
    return 0;
}