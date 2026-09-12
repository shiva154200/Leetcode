class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int i=0;i<m;i++ ){
            for(int j=0;j<n;j++){
                int c=0;
                if(i>0&&board[i-1][j])c++;
                if(j>0&&board[i][j-1])c++;
                if(i<m-1&&board[i+1][j])c++;
                if(j<n-1&&board[i][j+1])c++;
                if(i>0&&j>0&&board[i-1][j-1]) c++;
                if(i>0&&j<n-1&&board[i-1][j+1]) c++;
                if(i<m-1&&j>0&&board[i+1][j-1]) c++;
                if(i<m-1&&j<n-1&&board[i+1][j+1]) c++;
                
               cout<<c<<endl;
                if(board[i][j]){
                    if(c==2||c==3) v[i][j]=1;
                
                }
            else if(c==3) v[i][j]=1;



            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=v[i][j];
            }
        }
        
    }
};