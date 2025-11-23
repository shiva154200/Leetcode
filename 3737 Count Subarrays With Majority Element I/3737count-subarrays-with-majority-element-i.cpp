class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v(n,0);
        int c=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                c++;
                
            }
            v[i]=c;
        }

        c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int size=j-i+1;
                if((v[j]-c)>(size/2)) ans++;
            }
            c=v[i];
        }
        
      return ans;
    }
};