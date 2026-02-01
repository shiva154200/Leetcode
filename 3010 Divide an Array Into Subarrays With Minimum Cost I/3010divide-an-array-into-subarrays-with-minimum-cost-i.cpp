class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f,s;
        if(nums[1]<nums[2]){f=nums[1];s=nums[2];}
        else{
            f=nums[2];s=nums[1];
        } 
        for(int i=3;i<nums.size();i++){
            if(f>=nums[i]){
                s=f;
                f=nums[i];
            }
            else if(s>nums[i]) s=nums[i];
        }
        cout<<s<<" "<<f;
        return nums[0]+f+s;
        
      

        
    }
};