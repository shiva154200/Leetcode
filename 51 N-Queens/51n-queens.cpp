class Solution {
public:
   bool canweplace(int r,int c,int n,vector<string>&v){

    int l=r-1;
    while(l>=0){
        if(v[l][c]=='Q') return false;
        l--;
    }
    l=r-1;
    int d=c-1;
    while(l>=0&&d>=0){
        if(v[l][d]=='Q') return false;
        l--;
        d--;

    }
     l=r-1;
     d=c+1;
     while(l>=0&&d<n){
        if(v[l][d]=='Q') return false;
        l--;
        d++;

    }

return true;




   }
   void helper(int n,int r, vector<vector<string>>&ans, vector<string>&v){
    if(r==n){
        ans.push_back(v);
    }
    else{
        for(int i=0;i<n;i++){
            if(canweplace(r,i,n,v)){
                v[r][i]='Q';
                helper(n,r+1,ans,v);
                v[r][i]='.';

            }
        }

    }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s="";
        for(int i=0;i<n;i++) s.push_back('.');
        vector<string>v(n,s);
        helper(n,0,ans,v);
        return ans;

        
    }
};