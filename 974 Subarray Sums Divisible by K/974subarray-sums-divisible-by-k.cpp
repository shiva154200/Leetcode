class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int r=sum%k;
            ans += mp[r];
            if(r>0){
                ans+=mp[r-k];

            }
            if(r<0){
                ans+=mp[k+r];
                
            }
           
            mp[sum%k]++;
        }

        return ans;
        
    }
};