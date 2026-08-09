class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& grid,int m,int n, vector<vector<int>>&dp){
        
        if(i==m&&j==n) return grid[m][n];
        if (dp[i][j]!=-1) return dp[i][j];

        int mn=INT_MAX;
        if(i<m) mn=min(mn,fun(i+1,j,grid,m,n,dp));
        if(j<n) mn=min(mn,fun(i,j+1,grid,m,n,dp));

        return dp[i][j]=grid[i][j]+mn;
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
      
        return fun(0,0,grid,m,n,dp);
        
    }
};