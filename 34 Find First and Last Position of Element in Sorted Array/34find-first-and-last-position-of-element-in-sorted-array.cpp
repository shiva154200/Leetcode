class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {

        int l=0;
        int h=arr.size()-1;
        bool f=true;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                f=false;
                h=mid-1;
            }
            else if(arr[mid]<target) l=mid+1;
            else h=mid-1;
        }
        int lr=l;
        if(f) return {-1,-1};
        h=arr.size()-1;
           while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                f=false;
                l=mid+1;
            }
           
            else h=mid-1;
        }

        return {lr,h};


        
    }
};