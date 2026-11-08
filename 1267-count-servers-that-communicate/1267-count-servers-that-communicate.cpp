class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<int >row(n,0);
        vector<int>column(m,0);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(grid[i][j]) {
                row[i]++;
                column[j]++;
                }
            }
        }
        int ans=0;
           for(int i=0;i<n;i++){
          
            for(int j=0;j<m;j++){
                if(grid[i][j]&&(row[i]>1||column[j]>1)) {
                  ans++;
                }
            }
        }


   return ans;


        
    }
};