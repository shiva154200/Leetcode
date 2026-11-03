class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx,nums[i]);
        int ans=0;
        for(int x:nums) ans+=(mx-x);
        return ans;
        
    }
};