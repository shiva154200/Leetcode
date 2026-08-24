class Solution {
public:
    bool helper(int n, int mid,vector<int>& quantities){
        int ct=0;
        for(int x:quantities){
           ct += (x + mid - 1) / mid;
            if(ct>n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
      
        int l=1;
        int h=1;
        for(int x:quantities) h=max(x,h);
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            bool f=helper(n,mid,quantities);
            if(f) h=mid-1;
            else l=mid+1;
        }

        return l;
    
        
    }
};