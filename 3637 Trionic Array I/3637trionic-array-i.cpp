class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();

        if(nums[0]>nums[1]) return false;

        int c=0;
        bool f=false;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return false;
            if(!f&&nums[i]<nums[i-1]){
                c++;
                f=true;


            }
            if(f&&nums[i]>nums[i-1]){
                c++;
                f=false;
            }
            
        }

        if(c==2) return true;
        else return false;
        
        
    }
};