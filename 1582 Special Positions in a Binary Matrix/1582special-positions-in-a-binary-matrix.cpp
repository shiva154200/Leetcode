class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
      unordered_map<int,int> row;
      unordered_map<int,int> col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
         int c=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]&&row[i]==1&&col[j]==1){
                  c++;
                }
            }
        }

        return c;
    }
};