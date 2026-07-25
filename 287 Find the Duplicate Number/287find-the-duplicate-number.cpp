class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==i+1) i++;
            else if(nums[i]==nums[nums[i]-1]) return nums[i];
            else {swap(nums[i],nums[nums[i]-1]);}
            
        }

        return n;
        
    }
};