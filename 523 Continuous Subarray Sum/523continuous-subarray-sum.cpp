class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum%=k;
            bool f=mp.count(sum);
            if (f&& mp[sum ] < i - 1)
                return true;
            if (!f)
                mp[sum] = i;
        }
        return false;
    }
};