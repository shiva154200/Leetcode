class Solution {
public:
 typedef pair<int,int>p;

    int networkDelayTime(vector<vector<int>>& edges, int V, int k) {

          int E=edges.size();
          vector<vector<p>>adj(V+1);
        
        
        for(int i=0;i<E;i++){
            p r{edges[i][1],edges[i][2]};
            adj[edges[i][0]].push_back(r);
        }
        
        
       vector<int>ans(V+1,-1);
       ans[k]=0;
       
       queue<int>q;
       q.push(k);
       int l=0;
         int cur;
         int max=0;
       while(q.size()){

            cur=q.front();q.pop();
           
           
           for(int i=0;i<adj[cur].size();i++){
               
               int n=adj[cur][i].first;
               int w=adj[cur][i].second;
               
               if(ans[n]==-1||ans[n]>ans[cur]+w){
                   ans[n]=ans[cur]+w;
                   q.push(n);
               }
               
         
           }
           
       }
       int j=1;
       while(j<=V)
        {if (ans[j]==-1) return -1;
        if(max<ans[j]) max=ans[j];
        
        j++;}
       return max;
        
    }
};