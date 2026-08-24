class Solution {
public:
    
    int longestMonotonicSubarray(vector<int>& nums) {
       int n=nums.size();
       int c=1;
       for(int i=0;i<n;){
        int k=1;
        while(i<n-1&&nums[i+1]>nums[i]){
            k++;
            i++;
        }
       
      if(k==1) 
      { while(i<n-1&&nums[i+1]<nums[i]){
            k++;
            i++;
        }}

       if(i==n-1||nums[i]==nums[i+1]) i++;
    
        if(k>c) c=k;
       }
       return c;
    }
      

    
};