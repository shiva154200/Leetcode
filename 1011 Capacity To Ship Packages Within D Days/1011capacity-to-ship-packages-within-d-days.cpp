class Solution {
public:
    int requiredDays(vector<int>& weights, int capacity){
        int ct=1;
        int load=0;
        for(int x:weights){
            load+=x;
            if(load>capacity){
                ct+=1;
            load=x;
            } 

        }
        return ct;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int l=INT_MIN;
        int h=0;
        for(int x:weights){
            l=max(l,x);
            h+=x;
        }
        int mid;
        while(l<=h){
         mid=(l+h)/2;
         int d=requiredDays(weights,mid);
         if(d<=days){
            h=mid-1;
         }
         else l=mid+1;
        }
        return l;
    }
};