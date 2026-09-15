class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;

        }
        return true;

        
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        vector<vector<int>>dp(n,vector<int>(2,0));
        int i=0;
        int j=k-1;
        while(j<n){
            if(j-i+1>=k&&s[i]!=s[j])i++;
            else if(j-i+1>=k){
                if(ispalindrome(s,i,j)){
                    int prp=(i>0)?dp[i-1][0]:0;
                    if(dp[j][0]<prp+1)
                    dp[j]={prp+1,i};
                    i++;
                    j++;
                    
                }
                else{
                    i++;
                }

            }
            else{
            if(j>0) dp[j]=dp[j-1];
            i=0;
            if(dp[j][1]||dp[j][0])i=dp[j][1]+1;
            j++;
            }
           
            
        }
   return dp[n-1][0];

        
        
    }
};