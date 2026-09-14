class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        vector<vector<int>> A;

        // Store coordinates of all 1s in img1
        for (int i = 0; i < img1.size(); i++) {
            for (int j = 0; j < img1[i].size(); j++) {
                if (img1[i][j])
                    A.push_back({i, j});
            }
        }

        int r = img1.size();
        int c = img1[0].size();
        int ans = 0;

        // Try every possible shift
        for (int x = -r; x <= r; x++) {
            for (int y = -c; y <= c; y++) {

                int overlap = 0;

                for (auto &p : A) {
                    int X = p[0] + x;
                    int Y = p[1] + y;

                    // Check if shifted position is inside img2
                    if (0 <= X && X < r &&
                        0 <= Y && Y < c) {

                        if (img2[X][Y])
                            overlap++;
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};