class Solution {
public:
    int mod=1e9 + 7;
    int countGoodNumbers(long long n) {
        long long a=20;
        long long b=n/2;
        long long ans=1;
        while(b){
            if(b%2){
                ans*=a;
                ans%=mod;

            }
            a*=a;
            a%=mod;
            b/=2;

        }
        if(n%2){
            ans*=5;
        }
        return ans%mod;


        

   
        
    }


};