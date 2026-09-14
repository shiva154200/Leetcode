class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        vector<pair<int, int>> A, B;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j])
                    A.push_back({i, j});

                if (img2[i][j])
                    B.push_back({i, j});
            }
        }

        unordered_map<string, int> freq;
        int ans = 0;

        for (auto &a : A) {
            for (auto &b : B) {

                int dx = b.first - a.first;
                int dy = b.second - a.second;

                string key = to_string(dx) + "," + to_string(dy);

                freq[key]++;

                ans = max(ans, freq[key]);
            }
        }

        return ans;
    }
};