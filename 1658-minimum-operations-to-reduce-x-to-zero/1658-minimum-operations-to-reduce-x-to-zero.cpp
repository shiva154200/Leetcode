class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
       
        int sum=0;
       int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            if(sum==x){
                ans=(n-i);
            }

        }

        if(sum==x) return n;
        if(sum<x) return-1;

 cout<<sum;
        int maxsubarraylength=INT_MIN;
        int subarray_sum=0;
        int r=sum-subarray_sum;
        int right=0;
       

        for(int i=0;i<n;i++){
           subarray_sum+=nums[i];
           r=sum - subarray_sum;
        
          if(r==x){
            maxsubarraylength=max(maxsubarraylength,i-right+1);
            subarray_sum-=nums[right];
              right++;
          }

          else if(r<x) {
            while(r<x&&right<n){
                 subarray_sum-=nums[right];
                 right++;
              r=sum - subarray_sum;
  
            }
            if(r==x&&right<n){
            maxsubarraylength=max(maxsubarraylength,i-right+1);
            subarray_sum-=nums[right];
            right++;
          }

        
          } 
            
        }
        
        if(maxsubarraylength!=INT_MIN) ans= min(ans,(n-maxsubarraylength));
        if (ans!=INT_MAX) return ans;
        return -1;



        
       
       
     
    }
};