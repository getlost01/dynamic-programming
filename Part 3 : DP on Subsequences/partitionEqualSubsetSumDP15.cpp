class Solution {
public:
    bool check(vector<int>& nums, int i, int n,int sum, int total,        vector<vector<int>>& dp){
        if(total == sum * 2) return true;
        if(total < sum*2 ) return false;
        if(i == n) return false;
        if(dp[i][sum] != -1) return (bool)dp[i][sum];

        bool nottaken = check(nums,i+1,n,sum,total,dp);
        bool taken = check(nums,i+1,n,sum+nums[i],total,dp);

        dp[i][sum] = taken | nottaken;
        return taken | nottaken;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto i : nums) total += i;
        if(total%2) return false;

        vector<vector<int>> dp(nums.size(),vector<int>(total/2 + 1,-1));
        return check(nums,0,nums.size(),0,total,dp);
    }
};