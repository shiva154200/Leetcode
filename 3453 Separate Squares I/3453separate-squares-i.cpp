class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

      double upper = 0;
        double  lower = 0;
        int n = squares.size();
        double l =1e18;
        double h = -1e18;
        for (int i = 0; i < n; i++) {
            if (squares[i][1] < l)
                l = squares[i][1];
            if ((squares[i][1] + squares[i][2]) > h)
                h = (squares[i][1] + squares[i][2]);
        }
         double mid;
       while (h - l > 1e-6) {
            mid =(l+h) / 2;
            upper = 0;
            lower = 0;

            for (int i = 0; i < n; i++) {
             
                int y=squares[i][1];
                int ln=squares[i][2];

                double ly=((mid-y)<=0)?0
                :((mid-y)>=ln)?ln
                :mid-y;

                double hy=ln-ly;

                lower+=(ln*ly);
                upper+=(ln*hy);
              
               
            
            }
              if(lower>=upper) h=mid;
                else l=mid;

        }

        return mid;
    }
};