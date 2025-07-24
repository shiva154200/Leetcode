
class Solution {
public:
    typedef pair<int, int> p;

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int column = 0; column < n; column++) {
                if (visited[row][column] || grid[row][column] == '0') continue;

                c++;  // New island
                queue<p> q;
                q.push({row, column});
                visited[row][column] = 1;

                while (!q.empty()) {
                    p t = q.front(); q.pop();
                    int i = t.first;
                    int j = t.second;

                    // 8 directions (manually)
                    if (i != 0 && !visited[i - 1][j] && grid[i - 1][j] == '1') {
                        visited[i - 1][j] = 1;
                        q.push({i - 1, j});
                    }

                    if (i != m - 1 && !visited[i + 1][j] && grid[i + 1][j] == '1') {
                        visited[i + 1][j] = 1;
                        q.push({i + 1, j});
                    }

                    if (j != 0 && !visited[i][j - 1] && grid[i][j - 1] == '1') {
                        visited[i][j - 1] = 1;
                        q.push({i, j - 1});
                    }

                    if (j != n - 1 && !visited[i][j + 1] && grid[i][j + 1] == '1') {
                        visited[i][j + 1] = 1;
                        q.push({i, j + 1});
                    }

                    
                    
                }
            }
        }

        return c;
    }
};