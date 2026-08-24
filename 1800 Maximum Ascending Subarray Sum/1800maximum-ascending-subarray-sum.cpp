class Solution {
public:
    
        int maxAscendingSum(vector<int>& nums) {
       int n=nums.size();
       int s=0;
       for(int i=0;i<n;i++){
        int k=nums[i];
        while(i<n-1&&nums[i+1]>nums[i]){
            k+=nums[i+1];
            i++;
        }
        
        if(k>s) s=k;
       }
       return s;
    } 
    
};