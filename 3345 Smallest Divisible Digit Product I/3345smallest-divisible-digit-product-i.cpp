class Solution {
public:
    int smallestNumber(int n, int t) {

       
        int p=1;
        int m=n;
        while(m){
            p*=(m%10);
            m/=10;
        }

        if(!p) return n;

        int k=n%10;
        p/=k;

        while((p*k)%t&&k<10) k++;
        

        return n-n%10+k;



        
    }
};