class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n=nums.size();

        int i=n-2;
        while(i>=0&&nums[i]>=nums[i+1]) i--;

        int j=i+1;
        int k=n-1;
        while(j<k) {
            swap(nums[j++],nums[k--]);
        }

        if(i<0) return;

     j=i+1;

        while(nums[i]>=nums[j]) j++;

        swap(nums[i],nums[j]);

        
    }
};