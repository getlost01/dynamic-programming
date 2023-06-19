#include <bits/stdc++.h> 
int countSquares(int n, int m, vector<vector<int>> &arr) {
    for(int i = 1; i< n;++i){
        for(int j = 1; j<m;++j){
            if(arr[i][j])
                arr[i][j] += min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
        }
    }
    int c = 0;
    for(auto i: arr)
        for(auto j: i)
            c += j;
    
    return c;
}


