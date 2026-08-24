class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
       int n=nums.size();
       int c=1;
       for(int i=0;i<n;i++){
        int k=1;
        while(i<n-1&&nums[i+1]>nums[i]){
            k++;
            i++;
        }
       
        if(k>c) c=k;
       }
       return c;
    }
};