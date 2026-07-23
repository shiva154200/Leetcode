class Solution {
public:
    double myPow(double x, int n) {
        double  ans=pow(x*x,abs(n/2));
        if(n%2)ans*=abs(x);
        if(n<0) ans=1/ans;
        if(x<0&&n%2) return -1*ans;
        return ans;
        
        
        
    }
};