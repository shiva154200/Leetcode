class Solution {
public:
    void helper(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                int i, int j, bool& isClosed) {

        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = true;

        // If land touches the boundary, the island is not closed
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
            isClosed = false;
        }

        // Explore left
        if (j > 0 && grid[i][j - 1] == 0 && !visited[i][j - 1]) {
            helper(grid, visited, i, j - 1, isClosed);
        }

        // Explore right
        if (j < n - 1 && grid[i][j + 1] == 0 && !visited[i][j + 1]) {
            helper(grid, visited, i, j + 1, isClosed);
        }

        // Explore top
        if (i > 0 && grid[i - 1][j] == 0 && !visited[i - 1][j]) {
            helper(grid, visited, i - 1, j, isClosed);
        }

        // Explore bottom
        if (i < m - 1 && grid[i + 1][j] == 0 && !visited[i + 1][j]) {
            helper(grid, visited, i + 1, j, isClosed);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool isClosed = true;

                    helper(grid, visited, i, j, isClosed);

                    if (isClosed) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};