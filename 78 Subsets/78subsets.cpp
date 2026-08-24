class Solution {
public:

    void helper(vector<int>& nums,int idx,vector<int>v,vector<vector<int>>&ans)
    {
        if(idx==nums.size()){
            ans.push_back(v);
            return;
        }

        helper(nums,idx+1,v,ans);
        v.push_back(nums[idx]);
          helper(nums,idx+1,v,ans);
          return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>v;
        vector<vector<int>>ans;
        helper(nums,0,v,ans);

        return ans;


        
    }
};