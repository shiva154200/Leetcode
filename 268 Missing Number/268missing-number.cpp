class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int c=n;
        for(int i=0;i<nums.size();){
            if(nums[i]==i) i++;
            else if(nums[i]==n) {c=i;i++;}
            else{
                swap(nums[i],nums[nums[i]]);
            }
        }

        return c;
        
    }
};