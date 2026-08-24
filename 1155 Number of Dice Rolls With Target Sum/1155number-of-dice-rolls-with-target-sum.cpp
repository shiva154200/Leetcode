class Solution {
public:
    int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=target;j++){
                if(i==1&&j<=k) dp[i][j]=1;
               else {
                long long w=0;
                int l=min(j,k);
                while(l){
                    if(dp[i-1][j-l]!=-1) {
                        w+=dp[i-1][j-l];
                        w%=mod;}
                    l--;
                }
                if(w) dp[i][j]=w;
               } 


            }
        }
        if(dp[n][target]==-1) return 0;
        return dp[n][target];


        
    }
};