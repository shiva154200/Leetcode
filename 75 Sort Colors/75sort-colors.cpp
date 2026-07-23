class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            if(nums[l]<=1) l++;
           else  if(nums[h]>1) h--;
           else{swap(nums[l],nums[h]);
           l++;h--;
           }

        }
       l=0;
        while(l<=h){
            if(nums[l]==0) l++;
            else if(nums[h]==1)h--;
             else{swap(nums[l],nums[h]);
           l++;h--;
           }
        }
    


        
    }
};