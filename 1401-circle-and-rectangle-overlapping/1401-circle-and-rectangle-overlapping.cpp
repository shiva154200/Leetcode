class Solution {
public:
    double pow(double x) { return x * x; }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {

        double X_rectangle = (double(x1) + double(x2)) / 2.0;
        double Y_rectangle = (double(y1) + double(y2)) / 2.0;

        double Rectangle_radius = sqrt(pow(x2 - x1) + pow(y2 - y1)) / 2.0;
        double CenterDistance =
            sqrt(pow(X_rectangle - xCenter) + pow(Y_rectangle - yCenter));

        if (double(radius) + Rectangle_radius < CenterDistance)
            return false;
        int tangentx1 = yCenter - radius;
        int tangentx2 = yCenter + radius;
        int tangenty1 = xCenter - radius;
        int tangenty2 = xCenter + radius;

        bool X1 = false;
        bool Y1 = false;
        bool both_xtangent_outside = false;
        bool both_ytangent_outside = false;

        if ((y1 <= tangentx1 && y2 >= tangentx1) ||
            (y1 <= tangentx2 && y2 >= tangentx2))

            X1 = true;

        if ((x1 <= tangenty1 && x2 >= tangenty1) ||
            (x1 <= tangenty2 && x2 >= tangenty2))
            Y1 = true;

        if ((y1 > tangentx1 && y2 < tangentx2))
            both_xtangent_outside = true;
        if ((x1 > tangenty1 && x2 < tangenty2))
            both_ytangent_outside = true;

        if (X1 && Y1)
            return true;

        else if (both_ytangent_outside && both_xtangent_outside)
            return true;

        else if (X1 && both_ytangent_outside)
            return true;

        else if (Y1 && both_xtangent_outside) {
            return true;
        }

        return false;
    }
};
