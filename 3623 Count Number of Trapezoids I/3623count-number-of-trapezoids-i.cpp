class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long mod = 1000000007;
        int n = points.size();
        unordered_map<int, int> mp;
        vector<long long> temp;

        for (int i = 0; i < n; i++) {
            mp[points[i][1]]++;
        }

        for (auto& p : mp) {

            if (p.second > 1) {
                // long long s = (1LL * p.second * (p.second - 1)) / 2;
                long long s = ((long long)p.second * (long long)(p.second - 1))/2;

                temp.push_back(s);
            }
        }

        long long ans = 0;
        int sz = temp.size();
        if (!sz)
            return ans;
        long long sum = temp[0];

        for (int i = 1; i < sz; i++) {
            ans = (ans + temp[i] * sum) % mod;
            sum += temp[i];
        }

        return ans % mod;
    }
};