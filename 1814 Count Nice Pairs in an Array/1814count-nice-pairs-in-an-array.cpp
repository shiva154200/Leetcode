class Solution {
public:
    int diff(int x) {
        int k = x;
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return k - r;
    }

    int combination(int x) {
        // Use long long to avoid overflow
        return (1LL * x * (x - 1) / 2) % 1000000007;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        const int MOD = 1000000007;
        int count = 0;

        for (int x : nums) {
            mp[diff(x)]++;
        }

        for (auto x : mp) {
            if (x.second > 1) {
                count = (count + combination(x.second)) % MOD;
            }
        }

        return count;
    }
};
