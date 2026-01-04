class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans=0;

        for (int i=0;i<n;i++){

            if(nums[i]<6) continue;

            int c=0;
            int s=0;
           
            bool f=true;
             int j=2;
           while(j*j<nums[i]){
                
                if(nums[i]%j==0){

                    if(c>=2){
                        f=false;
                        break;
                    } 
                    c+=2;
                    s+=(nums[i]/j)+j;
                }
                j++;
            }

            if(f&&c==2&& j*j!=nums[i]) ans+=(s+1+nums[i]) ;

            
        }

        return ans;
    }
};