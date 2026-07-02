class Solution {
public:
    void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&v,int sum,int idx,bool f){

        if(sum==target){
            ans.push_back(v);
            return;
        }
       
        if(sum>target||idx>=candidates.size()) return;
        
        
        bool t=true;
        if(idx+1<candidates.size()&&candidates[idx]==candidates[idx+1]) t=false;
        helper(candidates,target,ans,v,sum,idx+1,t);

        v.push_back(candidates[idx]);
       if(f) helper(candidates,target,ans,v,sum+candidates[idx],idx+1,true);
        v.pop_back();
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
     helper( candidates,target,ans,v,0,0,true);
     return ans;
        
    }
};