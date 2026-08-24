class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int c=0;
         int x,y;
        for(int i=1;i<n;i++){
          x=points[i][0]-points[i-1][0];
          y=points[i][1]-points[i-1][1];

         
            c+=min(abs(x),abs(y));
            c+=(max(abs(x),abs(y))-min(abs(x),abs(y)));
          
            

        }
        return c;
        
    }
};