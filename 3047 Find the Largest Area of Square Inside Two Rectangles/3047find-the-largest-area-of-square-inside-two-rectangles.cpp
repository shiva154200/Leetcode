
class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int maxSide = 0;
    int n = bottomLeft.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int overlapX = min(topRight[i][0], topRight[j][0]) 
                       - max(bottomLeft[i][0], bottomLeft[j][0]);
        int overlapY = min(topRight[i][1], topRight[j][1]) 
                       - max(bottomLeft[i][1], bottomLeft[j][1]);

        if (overlapX > 0 && overlapY > 0) {
          maxSide = max(maxSide, min(overlapX, overlapY));
        }
      }
    }

    return 1LL * maxSide * maxSide;
  }
};