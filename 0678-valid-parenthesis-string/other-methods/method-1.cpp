class Solution {
public:

    bool helper(string &s,int i,int op, vector<vector<int>>&dp){


        if(i==s.size()&&op==0) return true;
        if(i==s.size()&&op) return false;
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
        return helper(s,0,op,dp);


        // int op=0;
        // for(int i=0;i<n;i++){
        //     if(op==0&&s[i]==')') return false;
        //     else if(op==0) op++;
        //     else if(s[i]=='*'&& )
        // }
        
    }
};