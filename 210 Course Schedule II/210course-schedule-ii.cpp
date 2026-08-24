class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(V);
	    
	    for(const auto &edge:prerequisites){
	        adj[edge[1]].push_back(edge[0]);
	    }
	
		vector<int>ans;
		
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
		    ans.push_back(a);
		    for(int j=0;j<adj[a].size();j++){
		        indegree[adj[a][j]]--;
		        if(indegree[adj[a][j]]==0) q.push(adj[a][j]);
		    }
		}
	    if(ans.size()!=V) return{};
		return ans;
    }
};