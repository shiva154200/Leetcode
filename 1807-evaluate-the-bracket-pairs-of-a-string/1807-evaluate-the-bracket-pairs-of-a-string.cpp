class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;
        for (vector<string>& v : knowledge) {
            mp[v[0]] = v[1];
        }
        string ans = "";
        bool f = false;
        string r = "";

        for (char& c : s) {
            if (c == '(') {
                f = true;
                r = "";
            } 
            else if (c == ')' && mp.count(r)) {
                ans += mp[r];
                f = false;
            } 
            else if (c == ')') {
                ans.push_back('?');
                f = false;

            } 
            else if (f) {
                r.push_back(c);
            } 
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};