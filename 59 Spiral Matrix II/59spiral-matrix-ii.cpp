class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c=n;
        vector<vector<int>>ans(n,vector<int>(n,0));

      int   row=0;
     int   col=0;
        int d=1;
        while(c){
             for(int i=col;i<col+c;i++){
                ans[row][i]=d++; 
             }
             col+=(c-1);
             c--;

             row++;

             if(c==0) break;

              for(int i=row;i<row+c;i++){
                ans[i][col]=d++; 
             }
             
             row+=(c-1);

             col--;
             

               for(int i=col;i>col-c;i--){
                ans[row][i]=d++; 
             }
             col=col-c+1;
             c--;
             row-=1;

             if(c==0) break;

              for(int i=row;i>row-c;i--){
                ans[i][col]=d++; 
             }

             col+=1;
             row=row-c+1;

            
        }
        return ans;
        
    }
};