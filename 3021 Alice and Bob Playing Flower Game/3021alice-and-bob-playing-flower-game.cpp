class Solution {
public:
    long long flowerGame(int n, int m) {
      
        long long c=0;
         long long p=n/2;
         long long q;
        if(n%2==0) q=p;
        else q=p+1;
          long long j=m/2;
          long long k;
        if(m%2==0)k=j;
        else k=j+1;
        
        c=(p*k)+(q*j);
        return c;
         
      

        

        
         return c;
        
    }
};