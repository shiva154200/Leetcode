class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j,int m,int n){
            if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;
        int z=grid[i][j];
        grid[i][j]=0;
            
        int up = dfs(grid, i-1, j,m,n);
        int down = dfs(grid, i+1, j,m,n);
        int left = dfs(grid, i, j-1,m,n);
        int right = dfs(grid, i, j+1,m,n);
        grid[i][j]=z;
        return z + max({up, down, left, right});


    }
    int getMaximumGold(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) ans=max(ans,dfs(grid,i,j,m,n));
            }
        }

        return ans;
        
    }
};