class Solution {
public:
    
    int scoreOfParentheses(string s) {
        int n=s.size();
 

      vector<int>dp(n+1,0);
      int op=0;

      for(char &c:s){
        if(c=='(') {op++;
        }
        else if(c==')'){
            dp[op]+=((dp[op+1])?2*dp[op+1]:1);
            dp[op+1]=0;
            op--;
        }
        
      }

      return dp[1];

      

  
        
    }
};