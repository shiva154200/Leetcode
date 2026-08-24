class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();

        int g = INT_MAX;
        int ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
    continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];

                if (g > abs(t - s)) {
                    g = abs(t - s);
                    ans = s;
                }

                if (s > t) k--;
                else if (s < t) j++;
                else return t;
            }
        }
        return ans;
    }
};