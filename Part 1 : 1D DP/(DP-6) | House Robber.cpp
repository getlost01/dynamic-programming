class Solution {
public:
    int checkDP(vector<int>& dp, int l,int r, vector<int>& nums){
        dp[l] = nums[l];
        dp[l+1] = max(nums[l],nums[l+1]);
        for(int i = l+2;i<r;++i){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[r-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        return max(checkDP(dp,0,n-1,nums),checkDP(dp,1,n,nums));
    }
};