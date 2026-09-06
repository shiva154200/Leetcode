class Solution {
public:
    int helper(string & s, string & t, vector<vector<int>>&dp,int si,int ti){
        if(ti==t.size()) return 1;
        
        if(t.length()-ti>s.length()-si) return 0;
        int ans=0;
       for(int i=si;i<s.length();i++){
        if(s[i]==t[ti]) {
            if(dp[i][ti]==-1) dp[i][ti]=helper(s,t,dp,i+1,ti+1);
            ans+=dp[i][ti];

        }
       }
       return ans;
    }
    int numDistinct(string s, string t) {
        if(t.length()>s.length()) return 0;
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return helper(s, t,dp,0,0);
        
    }
};