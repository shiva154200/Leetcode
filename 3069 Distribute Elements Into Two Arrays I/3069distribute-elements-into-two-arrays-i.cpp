class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        int i=0;int j=1;
        for(int k=2;k<n;k++){
            if(nums[i]>nums[j]){
                int r=k;
               while (r>i+1){
                swap(nums[r],nums[r-1]);r--;

               }
               i++;
               j++;
            }
            else j++;
        }

        return nums;
        
    }
};