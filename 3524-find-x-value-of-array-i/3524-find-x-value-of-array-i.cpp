class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        
        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;
            vector<long long> ndp(k, 0);
            
            ndp[r] += 1;
            
            for (int prev = 0; prev < k; prev++) {
                if (dp[prev] == 0) continue;
                int cur = (int)((1LL * prev * r) % k);
                ndp[cur] += dp[prev];
            }
            
            for (int j = 0; j < k; j++) {
                ans[j] += ndp[j];
                dp[j] = ndp[j];
            }
        }
        
        return ans;
    }
};