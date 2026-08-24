class Solution {
public:

    bool rowcheck(vector<vector<char>>& board){
        unordered_set<char>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
            st.clear();
        }
        return true;
    }

    
    bool colcheck(vector<vector<char>>& board){
        unordered_set<char>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(st.count(board[j][i])) return false;
                st.insert(board[j][i]);
            }
            st.clear();
        }
        return true;
    }

    bool singlegridcheck(int row, int col, vector<vector<char>>& board) {
    unordered_set<char> st;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (board[i][j] == '.') continue;
            if (st.count(board[i][j])) return false;
            st.insert(board[i][j]);
        }
    }
    return true;
}

    bool gridcheck(vector<vector<char>>& board){ 
        for(int i=0;i<9;i+=3){

            for(int j=0;j<9;j+=3){
               if(!singlegridcheck(i,j,board)) return false;
            }
        }
        return true;

    }

    bool isValidSudoku(vector<vector<char>>& board) {

    return (rowcheck(board)&&colcheck(board)&&gridcheck(board));

        
    }
};