#include <bits/stdc++.h> 
bool compare(string a, string b){
    if(a.size() != b.size() + 1) 
        return false;
    int canSkip = -1;
    for(int i = 0 ; i<a.size();++i){
        if(a[i] != b[i]){
            canSkip = i;
            break;
        }
    }
    return (a.substr(canSkip+1,a.size()-canSkip-1) == b.substr(canSkip,b.size()-canSkip));
}

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(),comp);
    vector<int> dp(n,1);
    int nax = 1;
    for(int i=0; i<=n-1; i++){
        for(int j = 0; j <=i-1; j ++){
            if( compare(arr[i], arr[j]) && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        if(dp[i] > nax)
            nax = dp[i];
    }
    return nax;
}