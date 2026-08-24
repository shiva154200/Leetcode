class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int pr=0;
        int nxt=0;
        int max=0;
        int j=0;
        while(j<n){
            while(j<n&&nums[j]==1) {
                j++;nxt++;}
                j++;
                if((nxt+pr)>max) max=nxt+pr;
                pr=nxt;
                nxt=0;
            
        }
        if(max==n) return n-1;
        return max;

    }
};