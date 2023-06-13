class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size(),m = t.size();
        int dp[n+1][m+1];
        for(int i = 0;i<=n;++i) dp[i][0] = 0;
        for(int i = 0;i<=m;++i) dp[0][i] = 0;

        for(int i = 1 ;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i = n, j = m;
        vector<int> ss,st;
        string str = "";
        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                ss.push_back(i-1);
                st.push_back(j-1);
                --i; --j;
            }else{
                if(dp[i-1][j] == dp[i][j])
                    --i;
                else
                    --j;
            }
        }
        reverse(ss.begin(),ss.end());
        reverse(st.begin(),st.end());
        int si = 0, ti = 0;
        for(int i = 0;i<ss.size();++i){
            for(int j = si ; j<ss[i]; ++j)
                str += s[j];
            for(int j = ti ; j<st[i]; ++j)
                str += t[j];
            si = ss[i]+1;
            ti = st[i]+1;
            str += s[ss[i]];
        }
        while(si<n){
            str += s[si];
            ++si;
        }
        while(ti<m){
            str += t[ti];
            ++ti;
        }

        return str;


    }
};