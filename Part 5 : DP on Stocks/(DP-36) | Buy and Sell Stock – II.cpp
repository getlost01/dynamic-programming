class Solution {
public:
    int maxProfit(vector<int>& val) {
        int n = val.size();
        vector<int> curr(2),prev(2,0);
        for(int i = n-1; i>= 0; --i){
            for(int j = 1; j>=0; --j){
                if(j)
                curr[j] = max(prev[0]-val[i],prev[1]);
                else
                curr[j] = max(prev[1]+val[i],prev[0]);
            }
            prev = curr;
        }
        return prev[1];
    }
};