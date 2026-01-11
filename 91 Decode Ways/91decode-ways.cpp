class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,0);
        if(s[0]=='0') return 0;
        dp[0]=1;

        for(int i=1;i<n;i++){
            int z=s[i]-48;
            int y=s[i-1]-48;
            if(z==0){
                if(y==0||y>2) return 0;
                dp[i]=(i>1)?dp[i-2]:1;
            }
            else{

                
            
            dp[i]+=dp[i-1];
            if(y!=0&&y*10+z<=26){
                dp[i]+=(i>1)?dp[i-2]:1;
            }
            }
            
         

        }
      return  dp[n-1];
    }
};