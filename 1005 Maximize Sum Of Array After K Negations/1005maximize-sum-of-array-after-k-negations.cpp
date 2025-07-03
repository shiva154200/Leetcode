class Solution {
public:


    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int r=INT_MAX;
        sort(nums.begin(), nums.end());
    
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) k=0;
            else if(k>0&&nums[i]<0){
                nums[i]=abs(nums[i]);
                sum+=nums[i];
              
                k--;
            }
            else sum+=nums[i];
            if(nums[i]<r) r=nums[i];
        }
           
        if(k%2)  sum-=(2*r);
        return sum;
    }
    
};