class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n=nums.size();
        int ct=0;
        int majority=nums[0];
        for(int i=0;i<n;i++){

            if(majority==nums[i]) ct++;
            else ct--;
            if(!ct){
                majority=nums[i];
                ct=1;
            }

            
        }
        return majority;
    }
};