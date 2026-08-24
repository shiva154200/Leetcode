class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        bool f=true;

        for(int i=0 ,k=0;i<n;i++,k++){
            for(int j=0 ,l=0;j<n;j++ ,l++){
                if(mat[i][j]!=target[k][l]) {
                    f=false;
                    break;
                }
            }
        }

        if(f) return f;
        f=true;

         for(int i=n-1, k=0;i>=0;i--,k++){
            for(int j=0 ,l=0;j<n;j++,l++){
                if(mat[j][i]!=target[k][l]) {
                    f=false;
                    break;
                }
            }
        }

        if(f) return f;
        f=true;

         for(int i=n-1,k=0;i>=0;i--,k++){
            for(int j=n-1,l=0;j>=0;j--,l++){
                if(mat[i][j]!=target[k][l]) {
                    f=false;
                    break;
                }
            }
        }

        if(f) return f;
        f=true;

        for(int i=0,k=0;i<n;i++,k++){
            for(int j=n-1,l=0;j>=0;j--,l++){
                if(mat[j][i]!=target[k][l]) {
                    f=false;
                    break;
                }
            }
        }

        return f;

        
    }
};