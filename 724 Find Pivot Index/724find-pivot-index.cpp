class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int r=nums[i];
            nums[i]=sum;
            sum=sum+r;
            
        }
        int p=-1;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1) {
                if(nums[i]==0) p=i;
                break;
            }
            else if(nums[i]==sum-nums[i+1]){
                p=i;
                break;
            }
        }
        return p;
    }
};