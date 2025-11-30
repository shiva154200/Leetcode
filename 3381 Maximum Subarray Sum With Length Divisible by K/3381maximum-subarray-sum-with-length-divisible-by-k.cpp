class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        long long prefixsum=0;

        // if(k==1){
        // long long sum1=LLONG_MIN;
        // long long CurSum=0;
        // for(int x:nums){
        //     CurSum+=x;
        //     sum1=max(sum1,CurSum);
        //     if(CurSum<0){
        //         CurSum=0;
        //     }
        // }
        
        // return sum1;
        // }

        unordered_map<int, long long >mp;

      
      
         for(int i=0;i<k-1;i++){
            prefixsum+=nums[i];
            mp[i+1]=prefixsum;
         }
         mp[0]=0;
          long long maxsum=LLONG_MIN;

         for(int i=k-1;i<n;i++){
             
             prefixsum+=nums[i];
             int t=(i+1)%k;

             maxsum=max(maxsum,(prefixsum-mp[t]));
             if(prefixsum<mp[t]) mp[t]=prefixsum;

             

         }

         return maxsum;


        
        
    }
};