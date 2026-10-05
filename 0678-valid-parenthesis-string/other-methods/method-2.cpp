class Solution {
public:

    bool helper(string &s,int i,int op, vector<vector<int>>&dp){

        if(i==s.size()&&op) return dp[i][op]=false;
        if(dp[i][op]!=-1) return dp[i][op];

        if(s[i]=='(') return dp[i][op]=helper(s,i+1,op+1,dp);
        else if(s[i]==')'&&op) return dp[i][op]=helper(s,i+1,op-1,dp);
        else if(s[i]==')') return dp[i][op]=false;
        else if(s[i]=='*'&& op) return dp[i][op]=(helper(s,i+1,op-1,dp) ||helper(s,i+1,op+1,dp)||helper(s,i+1,op,dp));
        else  return dp[i][op]=(helper(s,i+1,op+1,dp)||helper(s,i+1,op,dp));

    }
    bool checkValidString(string s) {
        int n=s.size();
        int op=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        dp[n][0]=1;
        return helper(s,0,op,dp);
        
    }
};