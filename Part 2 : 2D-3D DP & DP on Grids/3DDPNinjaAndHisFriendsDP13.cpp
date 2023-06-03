// Revisit Required 


class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(n, 0)));

        dp[0][0][n - 1] = (0 == n - 1) ? g[0][0] : g[0][0] + g[0][n - 1];

        for (int row = 1; row < m; row++) {

            for (int c1 = 0; c1 < min(n, row + 1); c1++) {
                for (int c2 = max(0, n - 1 - row); c2 < n; c2++) {
                    int prevMax = 0;

                    for (int dc1 = max(0, c1 - 1); dc1 <= min(n - 1, c1 + 1); dc1++) {
                        for (int dc2 = max(0, c2 - 1); dc2 <= min(n - 1, c2 + 1); dc2++) {
                                prevMax = max(prevMax, dp[row - 1][dc1][dc2]); 

                        }
                    }

                    if (c1 == c2) dp[row][c1][c2] = prevMax + g[row][c1];
                    else dp[row][c1][c2] = prevMax + g[row][c1] + g[row][c2];
                }
            }
        }

        int out = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out = max(out, dp[m - 1][i][j]);    
            }
        }

        return out;
    }
};