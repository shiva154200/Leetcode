
class Solution {
public:
   int ans=0;
    bool canweplace(int n,int i,int j,vector<string>&v){

       for(int k=i-1;k>=0;k--){
         if(v[k][j]=='Q') return false;
       }

       for(int p=i-1,q=j-1;p>=0&&q>=0;p--,q--){
              if(v[p][q]=='Q') return false;
       }

       for(int p=i-1,q=j+1;p>=0&&q<n;p--,q++){
              if(v[p][q]=='Q') return false;
       }

       return true;


    }

    void helper(int n,int i,vector<string>&v){

        if(i==n) {
            ans++;
            return;
        }
        
        for(int j=0;j<n;j++){

           if(canweplace(n,i,j,v)) {
            v[i][j]='Q';
            helper(n,i+1,v);
            v[i][j]='.';

           }

        }


    }
    int totalNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++) s.push_back('.');
        vector<string>v(n,s);

        helper(n,0,v);

        return ans;

        
    }
};