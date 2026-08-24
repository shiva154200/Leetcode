class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum=0;
        int max=0;
        int mi=0;
        for(int i=0;i<3;i++){
            sum+=nums[i];
            if(nums[i]>max) {max= nums[i];
               mi=i;}

        }
        sum-=max;
        if(sum<=max) return "none";

        if(max==sum/2) return "equilateral";

        int a=(mi+1)%3;
        int b=(mi+2)%3;

        if(nums[a]==nums[b]||nums[a]==max||nums[b]==max) return "isosceles";

        return "scalene";

        


    
        
    }
};