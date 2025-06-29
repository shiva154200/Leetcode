class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int md=-1;
        int m=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int d=m-nums[i];
            if(d>md&&d>0) md=d;
            if(nums[i]>m) m=nums[i];
        }
      return md;  
    }
};