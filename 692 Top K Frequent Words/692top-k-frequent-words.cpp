class Solution {
public:
    struct cmp {
    bool operator()(const pair<int,string>& a,
                    const pair<int,string>& b) const {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string x : words)
            mp[x]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>,
                      cmp>
            pq;

        for (const auto& [key, value] : mp) {

            pq.push({value,key});
            if(pq.size()>k){
                pq.pop();
            }

        }

        vector<string>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());


        return ans;
        
    }
};