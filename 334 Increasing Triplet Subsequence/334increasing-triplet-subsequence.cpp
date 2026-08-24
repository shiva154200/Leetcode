class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n=nums.size(); 
       vector<int>vmn(n);
       vector<int>vmx(n);
       int mn=nums[0];
       
       for(int i=1;i<n;i++){
        vmn[i]=mn;
        if(mn>nums[i]) mn=nums[i];
       }
        int mx=nums[n-1];
        for(int i=n-2;i>=0;i--){
        vmx[i]=mx;
        if(mx<nums[i]) mx=nums[i];
       }

       for(int i=1;i<n-1;i++){
        if(nums[i]>vmn[i]&&nums[i]<vmx[i]) return true;
       }

       return false;



      

      
       
   return false;
        
        
    }
};