class Solution {

public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i =0; int size=0;
        for (int j=0; j<nums.size();j++ ){
            if (nums[j]-nums[i] == 1) {
                size = max(size,j-i+1); 
            }
            while(nums[j]-nums[i] >1) {
                i++;
            } 
        }
        
        return size;
    }
};
    