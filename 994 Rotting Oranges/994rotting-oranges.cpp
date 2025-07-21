class Solution {
public:
    int orangesRotting(vector<vector<int>>& hospital) {
        int m=hospital.size();
        int n=hospital[0].size();
        queue<vector<int>>q;
        int c=0;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(hospital[i][j]) c++;
                if(hospital[i][j]==2){
                    vector<int>v(3);
                    v[0]=i;
                    v[1]=j;
                    v[2]=0;
                    q.push(v);
                }
            }
        }
        
        if(c==q.size()) return 0;
        c-=q.size();
        int t=0;
        
        while(q.size()){
            vector<int>v=q.front();q.pop();
            int i=v[0];
            int j=v[1];
            int ct=v[2];
            t=ct;
            
            if(i!=0&&hospital[i-1][j]==1){
                hospital[i-1][j]=2;
                 vector<int>v(3);
                    v[0]=i-1;
                    v[1]=j;
                    v[2]=(ct+1);
                    q.push(v);
                    c--;
            }
            
             if(i!=m-1&&hospital[i+1][j]==1){
                hospital[i+1][j]=2;
                 vector<int>v(3);
                    v[0]=i+1;
                    v[1]=j;
                    v[2]=(ct+1);
                    q.push(v);
                    c--;
            }
            
             if(j!=0&&hospital[i][j-1]==1){
                hospital[i][j-1]=2;
                 vector<int>v(3);
                    v[0]=i;
                    v[1]=j-1;
                    v[2]=(ct+1);
                    q.push(v);
                    c--;
            }
            
             if(j!=n-1&&hospital[i][j+1]==1){
                hospital[i][j+1]=2;
                 vector<int>v(3);
                    v[0]=i;
                    v[1]=j+1;
                    v[2]=(ct+1);
                    q.push(v);
                    c--;
            }
            
            
        }
        
        if(c>0) return -1;
        return t;
       
        
    }
};