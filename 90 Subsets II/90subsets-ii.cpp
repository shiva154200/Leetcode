class Solution {
public:

     void helper(vector<int>& nums,int idx,vector<int>v,vector<vector<int>>&ans,bool f)
    {
        if(idx==nums.size()){
            ans.push_back(v);
            return;
        }

        if(f) helper(nums,idx+1,v,ans,1);
        v.push_back(nums[idx]);
        if(idx<nums.size()-1&&nums[idx]==nums[idx+1])
          helper(nums,idx+1,v,ans,false);
        else{

         helper(nums,idx+1,v,ans,true);
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<int>v;
        vector<vector<int>>ans;
        helper(nums,0,v,ans,1);

        return ans; 
        
    }
};