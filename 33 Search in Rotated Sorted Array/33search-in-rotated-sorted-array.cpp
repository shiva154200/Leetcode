class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();
        if(n==1){
            return nums[0]==target?0:-1;
        }
      
        int l=0,h=n-1;
        int mid;
        while(1){
            mid=(l+h)/2;
            if(mid==n-1){
                if(nums[n-2]>nums[n-1]&&nums[0]>nums[n-1]){
                    mid=n-1;
                    break;
                }
                if(nums[mid]<nums[0]) h=mid-1;
                else l=0;
                
            }
              else if(mid==0){
                if(nums[1]>nums[0]&&nums[0]<nums[n-1]){
                    mid=0;
                    break;
                }
              
                else l=mid+1;
                
            }
            else{
                if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1]) break;
                else if(nums[mid]>nums[0]&&nums[mid]>nums[n-1]) l=mid+1;
                else h=mid-1;

            }

            
            
        }

        if(target>nums[n-1]){
            l=0;h=mid;
        }
        else{
            l=mid;
            h=n-1;
        }

        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;

            else h=mid-1;
        }
      return -1;
        


        
    }
};