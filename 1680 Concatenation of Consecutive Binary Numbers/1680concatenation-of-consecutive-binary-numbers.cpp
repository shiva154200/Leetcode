class Solution {
public:
int mod=1e9+7;
    
    int concatenatedBinary(int n) {
        long long r=0;

        for(int i=1;i<=n;i++){
            r=r%mod;
           r= r<<(int(log2(i)+1));
            r+=i;
        }

        return r%mod;

    
        
    }
};