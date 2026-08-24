class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m=nums.size();
        int n=nums[0].size();
        int l=0;
        int h=m-1;
        int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid][0]==target ) return true;
            else if(nums[mid][0]>target)    h=mid-1;
            else l=mid+1;
         
        }


        if(h==-1) return false;
        int row=h;

        l=0;h=n-1;
         while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[row][mid]==target ) return true;
            else if(nums[row][mid]>target)  h=mid-1;
            else l=mid+1;
           
        }

        return false;


        
    }
};