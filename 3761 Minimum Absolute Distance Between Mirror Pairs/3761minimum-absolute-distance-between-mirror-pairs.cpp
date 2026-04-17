class Solution {
public:
    
    int reverse(int k){
        while(k%10==0) k=k/10;
       
        int r=0;
        
        while(k){
            int l=k%10;
            r=r*10+l;
            k/=10;
            
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int mn=n;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
         
            int r=reverse(nums[i]);
            if(mp.count(nums[i])){
                mn=min(i-mp[nums[i]],mn);
            }
            mp[r]=i;

        }
        if(mn==n) return -1;
        return mn;
        
    }
};