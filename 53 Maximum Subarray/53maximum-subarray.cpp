class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;

        int cursum=0;

        int i=0;
        while(i<n){
            cursum+=nums[i];
            if(cursum>ans)ans=cursum;
            if(cursum<0){
                cursum=0;
            }
            i++;
        }

        return ans;



        

        
    }
};