class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int i=0;
        long long sum=0;
        int j=0;
        int r=1;
        while(i<nums.size()&&j<k){
            if(r<nums[i]) {
                sum+=r;
                r++;
                j++;
            }
            else if(nums[i]==r){
                r++ ;i++;

            }
            else{
                i++;

            }
            

        }

         while(j<k){
            sum+=r;
            r++;
            j++;
         }

         return sum;
        
    }
};