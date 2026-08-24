class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        while(i<n){
            if(nums[i]==i+1||nums[i]==-1) i++;
            else if(nums[i]==nums[nums[i]-1]) {ans.push_back(nums[i]);
            nums[i]=-1;i++;}
            else{
                swap(nums[i],nums[nums[i]-1]);
            }
        }
          
          return ans;
        
    }
};