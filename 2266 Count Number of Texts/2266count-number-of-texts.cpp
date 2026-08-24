class Solution {
public:
    int mod = 1e9 + 7;
    long long helper(string& s, int i, vector<int>& dp) {
        if(i==s.size()) return 1;
        if (dp[i])
            return dp[i];
       
   
        int c = 1;
        int j = i + 1;
        while (j < s.size() && s[j - 1] == s[j]) {
            c++;
            if (c == 4)
                break;
            j++;
        }
        if (c==1) {
            dp[i] = helper(s, i + 1, dp) % mod;

        } else if (c == 2) {
            dp[i] = (helper(s, i + 1, dp) % mod + helper(s, i + 2, dp) % mod)%mod;

        } else if (c == 3) {
            dp[i] = (helper(s, i + 1, dp) % mod + helper(s, i + 2, dp) % mod +
                    helper(s, i + 3, dp) % mod)%mod;
        } else if (c == 4 && (s[i] == '9' || s[i] == '7')) {
            dp[i] = (helper(s, i + 1, dp) % mod + helper(s, i + 2, dp) % mod +
                    helper(s, i + 3, dp) % mod + helper(s, i + 4, dp) % mod)%mod;
        }
        else{
             dp[i] = (helper(s, i + 1, dp) % mod + helper(s, i + 2, dp) % mod +
                    helper(s, i + 3, dp) % mod)%mod;

        }
        return dp[i];
    }
    int countTexts(string pressedKeys) {
        int ans = 0;
        int n = pressedKeys.size();
        vector<int> dp(n, 0);
        return helper(pressedKeys, 0, dp);
    }
};