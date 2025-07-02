class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0;
        int k=nums.size()-1;
        int i=0;
        while(i<nums.size()&&i<=k)
        {
            if(val==nums[i]) {
                c++;
                if(c==nums.size()) return 0;
                swap(nums[k],nums[i]);
               k= k-1;
                }
                else i++;


        }
        return nums.size()-c;
    }
};