class Solution {
public:
    int helper(string &s, string &t, vector<vector<int>>& dp, int si, int ti) {
     
        if (ti == t.size())
            return 1;

      
        if (si == s.size())
            return 0;

       
        if (dp[si][ti] != -1)
            return dp[si][ti];

        if (s[si] == t[ti]) {
            int take = helper(s, t, dp, si + 1, ti + 1);
            int skip = helper(s, t, dp, si + 1, ti);

            return dp[si][ti] = take + skip;
        }

        return dp[si][ti] = helper(s, t, dp, si + 1, ti);
    }

    int numDistinct(string s, string t) {
        if (t.length() > s.length())
            return 0;

        vector<vector<int>> dp(
            s.length(),
            vector<int>(t.length(), -1)
        );

        return helper(s, t, dp, 0, 0);
    }
};