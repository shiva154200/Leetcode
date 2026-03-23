class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                long long mx = LLONG_MIN, mn = LLONG_MAX;

                if (i > 0) {
                    mx = max(mx, max(dp[i-1][j].first * grid[i][j], dp[i-1][j].second * grid[i][j]));
                    mn = min(mn, min(dp[i-1][j].first * grid[i][j], dp[i-1][j].second * grid[i][j]));
                }

                if (j > 0) {
                    mx = max(mx, max(dp[i][j-1].first * grid[i][j], dp[i][j-1].second * grid[i][j]));
                    mn = min(mn, min(dp[i][j-1].first * grid[i][j], dp[i][j-1].second * grid[i][j]));
                }

                dp[i][j] = {mx, mn};
            }
        }

        long long res = dp[m-1][n-1].first;

        if (res < 0) return -1;

        return res % 1000000007;
    }
};