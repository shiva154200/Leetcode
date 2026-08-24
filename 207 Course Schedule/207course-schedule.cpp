class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(V);
	    
	    for(const auto &edge:prerequisites){
	        adj[edge[0]].push_back(edge[1]);
	    }
	
		int ans=0;
		
		queue<int>q;
		
		vector<int>indegree(V,0);
		for(int i=0;i<V;i++){
		    for(int j=0;j<adj[i].size();j++){
		        indegree[adj[i][j]]++;
		    }
		}
		
		for(int i=0;i<V;i++){
		    if(indegree[i]==0) q.push(i);
		}
		
		while(q.size()){
		    int a=q.front();
		    q.pop();
		    ans++;
		    for(int j=0;j<adj[a].size();j++){
		        indegree[adj[a][j]]--;
		        if(indegree[adj[a][j]]==0) q.push(adj[a][j]);
		    }
		}
	
		return ans==V;
        
    }
};