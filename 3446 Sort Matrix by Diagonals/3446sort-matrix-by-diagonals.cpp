

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, deque<int>> diag; 

   
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        
        for (auto& [key, dq] : diag) {
            vector<int> tmp(dq.begin(), dq.end());
            if (key >= 0) {
                sort(tmp.rbegin(), tmp.rend()); 
            } else {
                sort(tmp.begin(), tmp.end());   
            }
            dq = deque<int>(tmp.begin(), tmp.end());
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = diag[i - j].front();
                diag[i - j].pop_front();
            }
        }
        return grid;
    }
};

