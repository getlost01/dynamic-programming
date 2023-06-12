	int minSubsetSumDifference(vector<int>& arr, int n)
	{
		int total = 0;
        for(auto i : arr) total += i;

        vector<vector<bool>> dp(n+1,vector<bool>(total+1,false));
        for(int i = 0;i<=n;++i) 
            dp[i][0] = true;
        if(arr[0]<=total) 
            dp[0][arr[0]] = true;
            
        for(int ind = 1;ind<n;++ind){
            for(int tar = 1;tar<total;++tar){
                bool nottake = dp[ind-1][tar], take = false;
                if(arr[ind]<=tar)
                    take = dp[ind-1][tar - arr[ind]];
                dp[ind][tar] = take || nottake;
            }
        }

        int mx = 1e9;
        for(int i = 0;i<=total/2;++i)
            if(dp[n-1][i])
            mx = min(mx,abs(total - 2*i));
        return mx;
	}
