class Solution {
public:
    int numOfWays(int num) {
        long long mod=1e9+7;
        if (num==1) return 12;
        long long n=6,m=6;
        int i=2;
       

        while(i<num){
        
          long long n1=(n*3+m*2)%mod;
          long long m1=(m*2+n*2)%mod;
         n=n1;
         m=m1;
          i++;

        }

         return (int)((n * 5 + m * 4) % mod); 
       
       
     
        
    }
};

