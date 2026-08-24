class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=m-1,j=0;
        bool flag=0;
        while(i>=0&&j<n){
            if (matrix[i][j]==target) {flag=1;break;}
            else if(matrix[i][j]>target) i--;
            else j++;
        }
        return flag;
        
    }
};