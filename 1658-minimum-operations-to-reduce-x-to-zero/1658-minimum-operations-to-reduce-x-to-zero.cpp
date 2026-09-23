class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=n;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            mp[sum]=i;
        }
       
        int ans=(mp.count(x))?(n-mp[x]):INT_MAX;
        int prefixsum=0;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            if(prefixsum>x) break;
            if(mp.count(x-prefixsum)&&i<mp[x-prefixsum]){
                ans=min(ans,(i+1)+(n-mp[x-prefixsum]));
            }
        }
     if(ans!=INT_MAX) return ans;
     return -1;
        
    }
};