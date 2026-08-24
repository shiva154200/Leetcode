class Solution {
public:
    int helper(vector<int>& stoneValue, vector<int>& dp, int i) {
        int n = stoneValue.size();

        if (i >= n) return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        dp[i] = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];

            dp[i] = max(dp[i], take - helper(stoneValue, dp, i + k + 1));
        }

        return dp[i];
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int diff = helper(stoneValue, dp, 0);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};