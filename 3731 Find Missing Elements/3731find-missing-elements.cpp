class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=1;i<nums.size();i++){
          int c=nums[i-1]+1;
          while(c<nums[i]) {
             v.push_back(c);
             c++;
          }
        }

        return v;
        
    }
};