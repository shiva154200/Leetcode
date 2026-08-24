class Solution {
public:
    void helper(vector<vector<int>>& ans, int idx, vector<int> nums) {

        if (idx >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        sort(nums.begin()+idx,nums.end());
        int k = idx + 1;
        helper(ans, idx + 1, nums);
        while (k < nums.size()) {
            if (nums[k] != nums[idx]&&nums[k]!=nums[k-1]) {
                swap(nums[idx], nums[k]);
                helper(ans, idx + 1, nums);
                swap(nums[idx], nums[k]);
            }
            k++;
        }

        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        helper(ans, 0, nums);

        return ans;
    }
};