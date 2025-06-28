class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int x : arr) {
            int r = ((x % k) + k) % k;  // Normalize remainder to [0, k-1]
            mp[r]++;
        }

        for (auto& [rem, count] : mp) {
            if (rem == 0) {
                if (count % 2 != 0) return false;  // Remainder 0 must appear in even number
            } else {
                if (mp[rem] != mp[k - rem]) return false;
            }
        }

        return true;
    }
};
