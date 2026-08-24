class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
     if(poured<=0) return 0.0;
        vector<vector<double>>dp;
        vector<double>t(1,0);
   
        dp.push_back(t);
       
   


       dp[0][0]=poured;

    for(int i=1;i<=query_row;i++){
        t.push_back(0);
        dp.push_back(t);
        for(int j=0;j<=i;j++){
            
            if(j>0) dp[i][j]+=(dp[i-1][j-1]<=1)?0:(dp[i-1][j-1]-1)/2;
            if(j<i) dp[i][j]+=(dp[i-1][j]<=1)?0:(dp[i-1][j]-1)/2;
        }
    }




        return dp[query_row][query_glass]>=1?1:dp[query_row][query_glass];


        
    }
};