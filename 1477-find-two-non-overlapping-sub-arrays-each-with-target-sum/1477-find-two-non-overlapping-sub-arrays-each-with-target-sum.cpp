class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp;

        mp[arr[0]] = 0;
        mp[0] = -1;
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
            mp[arr[i]] = i;
        }

        vector<int> dp(n, 1e6);
        
        int ans = 1e6;
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            if (mp.count(x - target)) {
                int p = mp[x - target];
                dp[i] = (i > 0) ? min(dp[i - 1], i - p) : i - p;

                if (p != -1 && dp[p] != 1e6) {
                    ans = min(ans, i - p + dp[p]);
                }
            } else if (i > 0)
                dp[i] = dp[i - 1];
        }
        if (ans == 1e6)
            return -1;
        return ans;
    }
};