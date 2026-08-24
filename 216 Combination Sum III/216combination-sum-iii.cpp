class Solution {
public:

    void helper(int k,int n,vector<vector<int>>&ans,vector<int>&v,int sum,int idx){
        if(sum==n&&v.size()==k){
            ans.push_back(v);
            return;
        }

        if(sum>n||idx>9||v.size()>=k) return;

        helper(k,n,ans,v,sum,idx+1);

        v.push_back(idx);
        helper(k,n,ans,v,sum+idx,idx+1);
        v.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
     helper(k,n,ans,v,0,1);
     return ans;

        
    }
};