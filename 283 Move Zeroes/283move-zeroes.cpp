class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int c=0;
        for(int x:nums){
            if(x) c++;
        }
        int p=0;
         for(int x:nums){
            if(x) {
                nums[p++]=x;
            }
        }
        for(int i=c;i<nums.size();i++){
            nums[i]=0;
        }
     
        
    }
};