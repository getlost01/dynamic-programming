#include <bits/stdc++.h> 
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
  vector<int> prev(W+1,0), cur(W+1,0);
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            cur[cap] = max(notTaken, taken);
        }
        prev = cur;
    }
    
    return prev[W];
}