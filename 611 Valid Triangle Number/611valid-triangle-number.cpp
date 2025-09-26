class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n-1]<=0) return 0;
        int c=0;
        int i=0;
        while(i<n&&nums[i]==0) i++;
        for(i;i<n-2;i++){
            for(int j=i+2;j<n;j++){
                int k=nums[j]-nums[i];
                int r=i+1;
                while(r<=j&&nums[r]<=k ) r++;
                c+=(j-r);
            }
        }
              return c; 
        
    }
};