class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=1;
        while(i*i<=n){
            if(n%i==0){
                int k=n/i;
                ans+=(pow(nums[k-1],2)+pow(nums[i-1],2));
            }
            i++;
        }
        i--;
        if(i*i==n) ans-=pow(nums[i-1],2);

      
     return ans;
        
    }
};