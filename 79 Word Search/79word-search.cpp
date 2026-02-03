class Solution {
public:
      int m,n;
      
      

    bool helper(int i,int j,vector<vector<char>>& board, int idx,string & word, vector<vector<bool>>&visited){
        if(idx==word.size()) return true;



        if(i>0 && !visited[i-1][j] && board[i-1][j]==word[idx]) {
            visited[i-1][j]=true;
            if(helper(i-1,j,board,idx+1,word,visited)) return true;
              visited[i-1][j]=false;
        }

        if(j>0 && !visited[i][j-1] && board[i][j-1]==word[idx]) {
            visited[i][j-1]=true;
           if(helper(i,j-1,board,idx+1,word,visited))  return true;
             visited[i][j-1]=false;
        }

        if(i<m-1 && !visited[i+1][j] && board[i+1][j]==word[idx]) {
            visited[i+1][j]=true;
             if(helper(i+1,j,board,idx+1,word,visited))return true;
             visited[i+1][j]=false;
        }

        if(j<n-1 && !visited[i][j+1] && board[i][j+1]==word[idx]) {
            visited[i][j+1]=true;
           if(helper(i,j+1,board,idx+1,word,visited)) return true;
             visited[i][j+1]=false;
        }

        return false;

        
    }

    bool exist(vector<vector<char>>& board, string word) {
         m=board.size();
         n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=true ;
                if(helper(i,j,board,1,word,visited)) return true;
                visited[i][j]=false;} 
            }
        }

        return false;
       
    

    }
};