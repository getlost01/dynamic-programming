class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0), cur(n+1,0);

        for(int i = n-1;i>=0;--i){
            for(int j = i-1 ; j>=-1 ;--j){
                int len = dp[j+1];

                if(j == -1 || nums[i] > nums[j]) 
                    len = max(len, 1 + dp[i+1]);

                cur[j + 1] = len;
            }
            dp = cur;
        }

        return dp[0];
    }
};