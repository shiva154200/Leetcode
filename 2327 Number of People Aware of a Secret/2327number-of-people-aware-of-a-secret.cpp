class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        vector<long long> dp(forget + 1, 0);
        
        dp[1] = 1; 

        for (int day = 2; day <= n; day++) {
            long long f = 0;

            
            for (int j = delay; j < forget; j++) {
                f = (f + dp[j]) % MOD;
            }

         
            for (int k = forget; k > 1; k--) {
                dp[k] = dp[k - 1];
            }

            dp[1] = f; 
        }

       
        long long c = 0;
        for (int i = 1; i <= forget; i++) {
            c = (c + dp[i]) % MOD;
        }

        return (int)c;
    }
};
