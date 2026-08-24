class Solution {
public:

    // int helper(vector<vector<int>>& triangle,int i,int r, ){
    //     if(r==triangle.size()-1) return triangle[r][i];
        

    //      return triangle[r][i]+ min(helper(triangle,i,r+1),helper(triangle,i+1,r+1));
        
    // }
    int minimumTotal(vector<vector<int>>& t) {
       int n=t.size();
       int i=n-2;
       while(i>=0){
        for(int j=0;j<=i;j++){
            t[i][j]+=min(t[i+1][j],t[i+1][j+1]);
        }
        i--;
       }


       return t[0][0];
        
    }
};