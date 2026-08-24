class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
         int mx=0;
         int c=0;
      
        for (auto& p : mp) {
            if(p.second>mx){
                mx=p.second;
                c=p.second; 
            }
            else if(p.second==mx){
                c+=mx;
            }
        }

        return c;
    }
};