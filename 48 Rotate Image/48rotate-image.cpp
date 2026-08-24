class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n=matrix.size();
         int u=0,d=n-1;
        while(u<d){
            for (int j=0;j<n;j++){
               swap(matrix[u][j],matrix[d][j]);  
        }
        u++;d--;
        }
        

        for (int i=0;i<n;i++){
             for (int j=i;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);  
        }

        }
        
    }
};