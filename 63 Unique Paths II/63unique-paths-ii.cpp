class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid[0].size();
        int m=obstacleGrid.size();
        
        int v[m][n];
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1)  v[i][j]=0;
            
            else if(i==0||j==0){
                if(i>0) v[i][j]=v[i-1][j];
                else if(j>0) v[i][j]=v[i][j-1];
                else v[i][j]=1;
            }

            else v[i][j]=v[i-1][j]+v[i][j-1];
        }
       }
       return v[m-1][n-1];
    }
};