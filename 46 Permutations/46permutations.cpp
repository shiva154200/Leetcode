class Solution {
public:
    void helper( vector<vector<int>>&ans,int idx,vector<int>nums){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }
        int k=idx;
        while(k<nums.size()){
            swap(nums[idx],nums[k]);
            helper(ans,idx+1,nums);
            swap(nums[idx],nums[k]);
            k++;

        }


    return;


    }
    vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>>ans;
    helper(ans,0,nums);
    return ans;



        
    }
};