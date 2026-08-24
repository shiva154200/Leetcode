class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();

        int rem=0;
        for(int i=0;i<n;i++){

            rem=(rem+nums[i])%k;
        }
        
        return rem;
    }
};