class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1) i++;
            else{
                if(nums[nums[i]-1]==nums[i]) i++;
                else swap(nums[i],nums[nums[i]-1]);
            }
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) v.push_back(i+1);
        }
        return v;
        
    }
};