class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> low, high;
        long long sumLow = 0;
        long long ans = LLONG_MAX;

        auto balance = [&]() {
            while ((int)low.size() > k - 1) {
                auto it = prev(low.end());
                sumLow -= *it;
                high.insert(*it);
                low.erase(it);
            }
            while ((int)low.size() < k - 1 && !high.empty()) {
                auto it = high.begin();
                sumLow += *it;
                low.insert(*it);
                high.erase(it);
            }
        };

        auto add = [&](int x) {
            if (low.empty() || x <= *prev(low.end())) {
                low.insert(x);
                sumLow += x;
            } else {
                high.insert(x);
            }
            balance();
        };

        auto remove = [&](int x) {
            if (low.find(x) != low.end()) {
                low.erase(low.find(x));
                sumLow -= x;
            } else {
                high.erase(high.find(x));
            }
            balance();
        };

        // initial window
        for (int i = 1; i <= dist + 1 && i < nums.size(); i++)
            add(nums[i]);

        if ((int)low.size() == k - 1)
            ans = nums[0] + sumLow;

        for (int i = dist + 2; i < nums.size(); i++) {
            add(nums[i]);
            remove(nums[i - dist - 1]);
            if ((int)low.size() == k - 1)
                ans = min(ans, nums[0] + sumLow);
        }

        return ans;
    }
};

