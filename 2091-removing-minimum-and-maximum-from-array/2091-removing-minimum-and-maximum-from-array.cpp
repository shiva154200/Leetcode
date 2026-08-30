class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
       
        int mni=0;
        int mxi=0;
        for(int i=0;i<n;i++){
            if(nums[mxi]<nums[i]) mxi=i;
            if(nums[mni]>nums[i]) mni=i;
        }
       int l=mni;
       int r=mxi;
       if(mni>mxi){
        swap(l,r);
       }

       return min(r+1,min(n-l,l+1+n-r));

        
    }
};