class Solution {
  public:
    int minimumPairRemoval(vector<int>& nums) {
      int ans = 0;
      while (!is_sorted(nums.begin(), nums.end())) {
        int idx = 0;
        int minSum = nums[0] + nums[1];
        for (int i = 1; i < nums.size()-1; i++) {
          int sum = nums[i] + nums[i+1];
          if (sum < minSum) {
            minSum = sum;
            idx = i;
          }
        }
        nums[idx] = minSum;
        nums.erase(nums.begin()+idx+1);
        ans++;
      }
      return ans;
    }
};