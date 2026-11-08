class Solution {
public:
    bool helper(string s1, string s2, string s3,int i,int j, vector<vector<int>>&dp){
     if(dp[i][j]!=-1) return (dp[i][j]==1);
     if(i==s1.size()){
            if(s2.substr(j,100)==s3.substr(i+j,200)) {
                dp[i][j]=1;
                return true;
             
            }
            else{
                 dp[i][j]=0;
                 return false;
                
            }

  
        }
        else if(j==s2.size()){
            if(s1.substr(i,100)==s3.substr(i+j,200)) {
                dp[i][j]=1;
                return true;
            }
            else{
                 dp[i][j]=0;
                 return false;
            }
            
  
        }
       

       else if(s3[i+j]==s1[i]&&s3[i+j]==s2[j]){
            dp[i][j]=(helper(s1,s2,s3,i+1,j,dp)||helper(s1,s2,s3,i,j+1,dp)); 
             return (dp[i][j]==1);   
        }
        else if(s3[i+j]==s1[i]){
            dp[i][j]=helper(s1,s2,s3,i+1,j,dp);
             return (dp[i][j]==1);
        }
        else if(s3[i+j]==s2[j]){
             dp[i][j]=helper(s1,s2,s3,i,j+1,dp);
             return (dp[i][j]==1);
        }
        else {
            dp[i][j]=0;
            return false;
        }

       




    }

    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(m+n!=s3.size()) return false;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
      
        return helper(s1,s2,s3,0,0,dp);

      
    }
};