class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        if(v.size()<=2) return true;
       float a=v[0][0];
       float b=v[0][1];
       if(!(v[1][0]-a)){
        for(int i=2;i<v.size();i++){
            if(v[i][0]!=a) return false;
        }
        return true;
       }
       float m=(v[1][1]-b)/(v[1][0]-a);
       float ans=b-m*a;



       for(int i=2;i<v.size();i++){
        float r=v[i][1]-m*v[i][0];
        if(ans!=r) return false;
       }

       return true;

        
    }
};