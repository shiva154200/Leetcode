class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int> psm(n,0);
        psm[0]=nums[0];
        for(int i=1;i<n;i++){
            psm[i]=nums[i]+psm[i-1];
        }
         int st=0;
         int sum=0;

        //   for(int i=0;i<n;i++){
        //     cout<<psm[i]<<" ";
        // }
   int i=0;
        for(i;i<n;i++){
            if(mp.count(nums[i])&& st<=mp[nums[i]]){
               int pr= mp[nums[i]];
               sum=max(sum,psm[i-1]-psm[st]+nums[st]);
               st=pr+1;
              
            }
           
                mp[nums[i]]=i;
            
               
                
            
        }
         sum=max(sum,psm[i-1]-psm[st]+nums[st]);
        
        return sum;

        
        
    }
};