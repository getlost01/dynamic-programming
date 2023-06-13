class Solution {
public:
    int maxProfit(vector<int>& p) {
        int nin = p[0], out=0;
        for(int i = 1;i<p.size();++i){
            out = max(p[i]-nin,out);
            nin = min(nin,p[i]);
        }
    return out;
    }
};