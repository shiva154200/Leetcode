class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string> ans(score.size());
        int idx = pq.top().second;
        pq.pop();
        ans[idx] = "Gold Medal";
        if (!pq.empty()) {
            idx = pq.top().second;
            pq.pop();
            ans[idx] = "Silver Medal";
        }
        if (!pq.empty()) {
            idx = pq.top().second;
            pq.pop();
            ans[idx] = "Bronze Medal";
        }
        int n=4;
        while (!pq.empty()) {
            idx = pq.top().second;
            pq.pop();
            ans[idx] = to_string(n++);
        }
        return ans;
    }
};