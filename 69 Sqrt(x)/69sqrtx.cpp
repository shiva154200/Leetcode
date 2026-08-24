class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int h=x;
        long long mid;
        long long z;
        while(l<=h){
            mid=l+(h-l)/2;
            z=mid*mid;
            
            if(x==z) return mid;
            else if(z<x) l=mid+1;
            else h=mid-1;
        }
        return h;
    }
};