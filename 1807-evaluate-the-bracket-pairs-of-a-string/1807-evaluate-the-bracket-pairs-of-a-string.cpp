class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& v : knowledge) {
            mp[v[0]] = v[1];
        }
        string ans = "";
        bool f = false;
        string r = "";
        for (char& c : s) {
            if (c == '(') {
                f = true;
                r = "";
            } else if (c == ')') {
                if (mp.count(r)) {
                    ans += mp[r];
                }
                else {
                    ans.push_back('?');
                }
                f = false;
            } else if (f) {
                r.push_back(c);
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};