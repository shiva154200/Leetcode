class Solution {
public:
    int findKOr(vector<int>& nums, int k) {

        vector<int>v(32,0);
       
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i] & (1LL<<j)){
                    v[j]++;
                }
            }
        }

         int result=0;
         long long m=1;
         for(int i=0;i<32;i++){
            if(v[i]>=k){
                result+=m;
            }
            m*=2;
         }

    return result;


        
        
    }
};