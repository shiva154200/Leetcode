class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n=arr.size();
        int l=0;int h=n-1;
        int mid;
      
        while(l<=h){
            mid=(l+h)/2;

            if(arr[mid]==x) break;
            else if(arr[mid]<x) l=mid+1;
            else h=mid-1;

        }
        vector<int>ans;
        if(l<=h){
          ans.push_back(x);
          l=mid-1;
          h=mid+1;
        }
        else swap(l,h);

        while(ans.size()<k){
            if(l<0){
                while(ans.size()<k) ans.push_back(arr[h++]);
                break;
            }
            if(h>=n){
                 while(ans.size()<k) ans.push_back(arr[l--]);
                break;
            }
            if(x-arr[l]<=arr[h]-x) {
                ans.push_back(arr[l]);
                l--;
            }
            else{
                ans.push_back(arr[h]);
                h++;
            }
        }
     sort(ans.begin(),ans.end());
        return ans;
        
    }
};