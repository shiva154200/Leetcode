class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        long long h = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                h += grid[i][j];
                if(j==n-1&&2*h==total) return true;
            }
        }

        long long v=0;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v+= grid[j][i];
                if(j==m-1&&2*v==total) return true;
            }
        }

        return false;
    }


};