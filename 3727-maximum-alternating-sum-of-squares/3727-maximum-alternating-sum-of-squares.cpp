class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end(),[](int &a,int &b){
            return abs(a)>abs(b);
        });

        long long ans=0;
        int i=0;


        while(i<(n+1)/2){
            ans+=(nums[i]*nums[i]);
            i++;
        }

        while(i<n){
            ans-=(nums[i]*nums[i]);
            i++;
        }

        return ans;
        


        
    }
};