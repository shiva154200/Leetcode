class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0;
        int h = n - 1;
        int mid;
        int ans = n-1;

        for (int i = 0; i < n - 1; i++) {
            long long mn = nums[i];
            l = i + 1;
            h = n - 1;
            bool f = false;
            while (l <= h) {
                mid = l + (h-l) / 2;
                if (nums[mid] <= k * mn) {
                    l = mid + 1;
                    f = true;
                } else {
                    h = mid - 1;
                }
            }

            if (f) {
                ans = min(ans, i + n -1 - h);
            }


        }

        return ans;
    }
};