class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        int s=1;
        for(int i=0;i<n;i++){
            prefix[i]=s;
            s*=nums[i];
        }
        s=1;
         for(int i=n-1;i>=0;i--){
            prefix[i]*=s;
            s*=nums[i];
        }

        return prefix;


        
    }
};