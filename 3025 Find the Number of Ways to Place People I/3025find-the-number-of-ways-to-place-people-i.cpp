
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int n = points.size();

        for (int i = 1; i < n; i++) {

            int j = i;
            while (j > 0) {
                if (points[j][0] < points[j - 1][0]) {
                    swap(points[j], points[j - 1]);
                    j--;
                }

                else if (points[j][0] == points[j - 1][0]) {

                    
                    if (points[j][1] > points[j - 1][1])
                       { swap(points[j], points[j - 1]);
                           j--;
                       }
                    else break;
                }

                else
                    break;
            }
        }

        int c = 0;
       for (int i = 0; i < n-1; i++) {
    int ymax = -1;
    for (int j=i+1; j<n; j++) {
        if (points[i][1] >= points[j][1]) {
            if (points[j][1] > ymax) {
                c++;
                ymax = points[j][1];
            }
        }
    }
}

      
    return c;
    }
};
