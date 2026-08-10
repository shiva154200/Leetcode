class Solution {
public:

    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,0);
        dp[0]=false;
        dp[1]=1;
       
        for(int i=2;i<=n;i++){
            int k=1;
            while(k*k<=i){
                if(!dp[i-k*k]){
                    dp[i]=1;
                    break;
                }
                k++;
            }
        }
      return dp[n];

        
    }
};