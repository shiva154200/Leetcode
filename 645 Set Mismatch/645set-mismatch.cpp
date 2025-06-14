class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int i=0;
         while(i<n){
            if(nums[i]==i+1||nums[nums[i]-1]==nums[i]) i++;
            else {swap(nums[i],nums[nums[i]-1]);
            }
           
         }
          i=0;
            
            while(i<n&&nums[i]==i+1){
                i++;
            }
            vector<int>v;
            v.push_back(nums[i]);
            
            v.push_back(i+1);
            
            return v;
    }
};