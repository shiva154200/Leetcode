class Solution {
    
public:
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
void helper(string &G,string &ans,int n,int k){
    if(k==1) {
     
        ans=ans+G;
        return;
    }

    int r=fact(n-1);
    int s=k/r;
    if(k%r==0){
        ans+=G[s-1];
        for(int i=G.length()-1;i>=0;i--){
            if(i==s-1) continue;
            ans+=G[i];
        }
        return ;
    }
    else{
        ans+=G[s];
        G=G.substr(0,s)+G.substr(s+1);
        n=n-1;
     
        if(k>r) k=k-s*r;
        helper(G,ans,n,k);
    }
    
}
    string getPermutation(int n, int k) {
        string G;
        for(int i=1;i<=n;i++){
            G+=to_string(i);
        }
          string ans="";
          helper(G,ans,n,k);
          return ans;
        
        
    }
};