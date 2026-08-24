class Solution {
public:
    int findLucky(vector<int>& arr) {
       int n=arr.size();
       sort(arr.begin(),arr.end()) ;
       int c=0;
       int k=arr[n-1];
       for(int i=n-1;i>=0;i--){
        if(arr[i]==k) c++;
        else{
           if( arr[i+1]==c) return arr[i+1];
           c=1;
           k=arr[i];
        }
       }
       if(arr[0]==c) return c;
     return -1;
    }
};