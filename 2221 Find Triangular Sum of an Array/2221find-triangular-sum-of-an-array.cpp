class Solution {
public:
    int helper(vector<int>nums,vector<int>dummy,int n){
        for(int i=0;i<n-1;i++){
            dummy[i]=(nums[i]+nums[i+1])%10;
        }

        nums.pop_back();nums.pop_back();
        if(n-1==1) return dummy[0];
        return helper(dummy,nums,n-1);
        
    } 
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dumy(n-1);
        
        return helper(nums,dumy,n);
        
    }
};