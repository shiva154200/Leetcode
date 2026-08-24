class Solution {
public:
    vector<vector<int>> ans;


    void helper(int n,int k,int i,vector<int>&v){
        if(k==0) {
            ans.push_back(v);
            return;
        }
        while(i+k<=n){
            v.push_back(i+1);
            helper(n,k-1,i+1,v);
            v.pop_back();
            i++;
        }

      return;  

    }
    vector<vector<int>> combine(int n, int k) {

       
        vector<int>v;
        helper(n,k,0,v);

        return ans;
        
    }
};