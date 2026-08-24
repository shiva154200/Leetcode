class Solution {
public:
   

    int minimumDistance(vector<int>& nums) {
        int mn=INT_MAX;
        unordered_map<int,vector<int>>mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
           mp[nums[i]].push_back(i);
           int k=mp[nums[i]].size();
           if(k>2){
            mn=min (mn,2*(mp[nums[i]][k-1]-mp[nums[i]][k-3]));
           }


        }
        if(mn==INT_MAX) return -1;
        return mn;

    }
};