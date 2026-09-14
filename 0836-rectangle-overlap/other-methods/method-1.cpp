class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        if ((x1 == rec2[0] && x2 == rec2[2]) &&
            (((y1 > rec2[1]) && (y1 < rec2[3])) ||
             ((y2 > rec2[1]) && (y2 < rec2[3])) ||
             ((y1 == rec2[1]) && (y2 == rec2[3])))) {
            cout << 1;
            return true;
        }

        if ((y1 == rec2[1] && y2 == rec2[3]) &&
            (((x1 > rec2[0]) && (x1 < rec2[2])) ||
             ((x2 > rec2[0]) && (x2 < rec2[2])) ||
             ((x1 == rec2[0]) && (x2 == rec2[2])))) {
            cout << 2;
            return true;
        }

        if (((x1 > rec2[0] && x1 < rec2[2]) ||
             (x2 > rec2[0] && x2 < rec2[2])) &&
            ((y1 < rec2[1] && y2 > rec2[1]) || (y1 < rec2[3] && y2 > rec2[3]) ||
             ((y1 > rec2[1] && y1 < rec2[3]) &&
              (y2 > rec2[1] && y2 < rec2[3])))) {
            cout << 3;
            return true;
        }

        if (((x1 < rec2[0] && x2 > rec2[0]) ||
             (x1 < rec2[2] && x2 > rec2[2])) &&
            ((y1 > rec2[1] && y1 < rec2[3]) || (y2 > rec2[1] && y2 < rec2[3]) ||
             ((y1 < rec2[1] && y2 > rec2[1]) &&
              (y1 < rec2[3] && y2 > rec2[3])))) {
            cout << 4;
            return true;
        }

        cout << 9;

        return false;
    }
};