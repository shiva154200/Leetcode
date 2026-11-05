class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0;
        int c=0;
        if(nums[0]==1) c=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==1&&nums[i-1]==1){
                c++;
            }
            else if(nums[i]==0){
                mx=max(mx,c);
                c=0;
            }
            else{
                c=1;
            }

        
        }
         return max(mx,c);
        
    }
};