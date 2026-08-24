class Solution {
public:
    bool helper(int node, vector<vector<int>>& adj, vector<int>& color) {

        color[node] = 0;

        queue<int> s;
        s.push(node);
        while (s.size()) {
            int Top = s.front();
            s.pop();

            for (int i = 0; i < adj[Top].size(); i++) {
                if (color[adj[Top][i]] == -1) {
                    color[adj[Top][i]] = (color[Top] + 1) % 2;
                    s.push(adj[Top][i]);
                }

                else {
                    if (color[Top] == color[adj[Top][i]])
                        return false;
                }
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1, -1);
        for (int i = 1; i<n; i++) {
            if ((color[i] == -1) && (!helper(i, graph, color)))
                return false;
        }

        return true;
    }


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1] );
            graph[dislikes[i][1]].push_back(dislikes[i][0] );
            
        }

        return isBipartite(graph);
    }
};