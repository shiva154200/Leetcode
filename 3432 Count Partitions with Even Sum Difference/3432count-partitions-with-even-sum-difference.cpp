class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();

        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
          int r=nums[n-1]%2;
          if(!r) return n-1;
        
        return 0;

        
        

    }
};