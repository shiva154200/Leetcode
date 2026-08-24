class Solution {
public:
    int mod = 1e9+7;

    int numberOfPaths(vector<vector<int>>& grid, int t) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(t,0)));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    v[0][0][grid[0][0]%t] = 1;
                    continue;
                }

                for(int r=0;r<t;r++){
                    if(i>0){
                        int newRem = (r + grid[i][j]) % t;
                        v[i][j][newRem] = (v[i][j][newRem] + v[i-1][j][r]) % mod;
                    }
                    if(j>0){
                        int newRem = (r + grid[i][j]) % t;
                        v[i][j][newRem] = (v[i][j][newRem] + v[i][j-1][r]) % mod;
                    }
                }
            }
        }

        return v[n-1][m-1][0];
    }
};
