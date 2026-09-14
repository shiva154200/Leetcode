class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

      

   vector<vector<int>>A;

        int ans=0;
        for(int i=0;i<img1.size();i++ ){
            for(int j=0;j<img1[i].size();j++){
                if(img1[i][j]) A.push_back({i,j});

            }
        }
       
       int r=img1.size();
       int c=img1[0].size();
    
        for(int x=-c;x<=c;x++){
            for(int y=-r;y<=r;y++){
                int z=0;

                for(auto &p:A){
                    int X=p[0]+x;
                    int Y=p[1]+y;
                    if(0<=X&&X<r&&0<=Y&&Y<c){
                        if(img2[X][Y]) z++;
                    }
                }

                ans=max(ans,z);

            }
        }
      return ans;  
    }
};