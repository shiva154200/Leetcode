class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;

        unordered_map<string, int> id;
        int m = original.size();
        int p = 0;

        unordered_set<int> lens;

        for (int i = 0; i < m; i++) {
            if (!id.count(original[i])) id[original[i]] = p++;
            if (!id.count(changed[i]))  id[changed[i]]  = p++;
            lens.insert(original[i].size());
        }

        vector<vector<long long>> matrix(p, vector<long long>(p, INF));

        for (int i = 0; i < p; i++) matrix[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            matrix[u][v] = min(matrix[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < p; k++)
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    if (matrix[i][k] != INF && matrix[k][j] != INF)
                        matrix[i][j] = min(matrix[i][j],
                                           matrix[i][k] + matrix[k][j]);

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

         
            if (source[i-1] == target[i-1])
                dp[i] = dp[i-1];

            for (int len : lens) {
                if (len > i) continue;

                int start = i - len;

                string s = source.substr(start, len);
                string t = target.substr(start, len);

                if (id.count(s) && id.count(t)) {
                    int u = id[s];
                    int v = id[t];
                    if (matrix[u][v] != INF)
                        dp[i] = min(dp[i],
                                    dp[start] + matrix[u][v]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
