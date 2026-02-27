class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n=nums.size();

        int p=-1;
        int c=1;
         bool f=false;
        for(int i=1;i<n;i++){
           
         
            if(nums[i]>nums[i-1]) c++;
            else{
                if(c>=(2*k)) return true;
                if(c>=k) {
                    if(f) return true;
                    f=true;
                    c=1;

                }
                else{
                    f=false;
                    c=1;
                }
                
            }
            
        }
        if(c>=(2*k)) return true;

         if(f&&c>=k) return true;
         return false;
    
        
    }
};