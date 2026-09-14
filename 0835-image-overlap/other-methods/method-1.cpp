class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m=0;

        struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return p.first ^ (p.second << 1);
    }
};

        unordered_set<pair<int,int>,PairHash>A;
        unordered_set<pair<int,int>,PairHash>B;

        int ans=0;
        for(int i=0;i<img1.size();i++ ){
            for(int j=0;j<img1[i].size();j++){
                if(img1[i][j]) A.insert({i,j});
                if(img2[i][j]) B.insert({i,j});

            }
        }
       
       int r=img1.size();
       int c=img1[0].size();
    
        for(int x=-c;x<=c;x++){
            for(int y=-r;y<=r;y++){
                int z=0;

                for(auto &p:A){
                    int r=p.first+x;
                    int c=p.second+y;
                    if(B.count({r,c})) z++;
                }

                ans=max(ans,z);

            }
        }
      return ans;  
    }
};