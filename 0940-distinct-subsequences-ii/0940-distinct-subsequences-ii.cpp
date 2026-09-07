class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        
        int mod = 1e9 + 7;
        long long total=0;


        vector<int>dp(26,0);
    
        for(int i=0;i<n;i++){
     
        long long t=total;
        total=2*total+1;
    total=total-dp[s[i]-97]+mod;
        dp[s[i]-97]=(t+1)%mod;
        total%=mod;
        cout<<i<<":"<<total<<endl;

        }

        return total%mod;
        
    }
};