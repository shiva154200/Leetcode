class Solution {
public:
    bool helper(int target,vector<int>& arr,int d){

        int l=0;
        int h=arr.size()-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==target) return false;
            else if(arr[mid]<target) l=mid+1;
            else h=mid-1;
        }

        if(h>=0 && abs(arr[h]-target)<=d) return false;
        if(h+1<arr.size() && abs(arr[h+1]-target)<=d) return false;
        return true;
    



        

    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;

        for (int &x:arr1){
            if(helper(x,arr2,d)) ans++;
        }

        return ans;
        
    }
};