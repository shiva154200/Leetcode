class Solution {
public:

    void helper(vector<vector<int>>&ans,  vector<int>&v,vector<int>& candidates, int target,int sum,int idx){

      if(sum==target) {
        ans.push_back(v);
        return;
      }
      if(idx>=candidates.size()||sum>target) return;

      helper(ans,v,candidates,target,sum,idx+1);
      v.push_back(candidates[idx]);
     helper(ans,v,candidates,target,sum+candidates[idx],idx);
      v.pop_back();



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>v;
        helper(ans,v,candidates,target,0,0);

        return ans;
        
    }
};