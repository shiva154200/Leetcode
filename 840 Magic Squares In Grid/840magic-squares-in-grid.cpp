

class Solution {
public:
    vector<vector<int>> rowprefix;
    vector<vector<int>> colprefix;

    bool helper(int i,int j,vector<vector<int>>& grid) {

        unordered_set<int>st;
        int rl=i+3-1;
        int cl=j+3-1;

        for(int p=i;p<=rl;p++){
            for(int q=j;q<=cl;q++){
                if( grid[p][q]<1|| grid[p][q]>9 || st.count(grid[p][q])) return false;
                st.insert(grid[p][q]);

            }
        }

        //row check
        int s=rowprefix[i][cl];

        if(j>0) s-=rowprefix[i][j-1];
        int t=i;
        while(t<=rl){
            int z=rowprefix[t][cl];
            if(j>0) z-=rowprefix[t][j-1];
            if (s!=z) return false;
            t++;
        }

        //col check

    

         t=j;
        while(t<=cl){
            int z=colprefix[rl][t];
            if(i>0) z-=colprefix[i-1][t];
            if (s!=z) return false;
            t++;
        }


       //diagonal check 1
       int z=0;
        int p=i,q=j;
       while(p<=rl&&q<=cl){
        z+=grid[p++][q++];
       }

       if(z!=s) return false;

       //diagonal check 2

       z=0;
       p=i;q=cl;
       while(q>=j){
        z+=grid[p++][q--];
       }

        if(z!=s) return false;

        return true;

  

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        rowprefix = grid;
        colprefix = grid;

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                rowprefix[i][j] += rowprefix[i][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                colprefix[j][i] += colprefix[j - 1][i];
            }
        }

        int ct=0;
        for(int i=0;i+2<m;i++){
            for(int j=0;j+2<n;j++){
                if(helper(i,j,grid)) ct++;
            }
        }
      return ct;
      
    }
};