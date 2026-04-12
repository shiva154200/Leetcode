class Solution {
public:
    bool isprime (int n){
        if(n==1)return false;
        if(n==2) return true;
       int k=2;
        while(k*k<=n){
            if(n%k==0) return false;
            k++;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int mn=INT_MAX;
        vector<int>v={-1,-1};
        int prev=0;
        for(int i=left;i<=right;i++ ){
            if(isprime(i)){
                if(prev){
                    if(i-prev<mn) {
                        mn=i-prev;
                        v[0]=prev;
                        v[1]=i;
                    }
                
                }
                prev=i;
            }
        }


      return v;
        
    }
};