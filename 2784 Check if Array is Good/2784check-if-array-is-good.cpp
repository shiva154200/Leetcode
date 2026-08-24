class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>v(n);
        for(int x:nums){
            if(x>n-1) return false;
            v[x]++;
        }
        if(v[n-1]!=2) return false;
        for(int i=1;i<n-1;i++){
            if(v[i]!=1) return false;
        }

        return true;
       
        
    }
};