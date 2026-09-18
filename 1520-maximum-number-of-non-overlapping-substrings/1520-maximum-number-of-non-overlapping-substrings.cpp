class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> foc(26, -1); // first occurence
        vector<int> loc(26, -1); // last occurence

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (foc[idx] == -1)
                foc[idx] = i;
            loc[idx] = i;
        }

        vector<vector<int>> ranges;//valid substr ranges

        for (int i = 0; i < 26; i++) {

            if (foc[i] != -1) { //check char is present or not
                int f = foc[i];
                int l = loc[i];
                bool isvalid = true;
                for (int j = f; j <= l; j++) {
                    if (foc[s[j] - 'a'] < f) {
                        isvalid = false;
                        break;
                    }
                    l = max(l, loc[s[j] - 'a']);
                }

                if (isvalid) {
                    ranges.push_back({f, l});
                }
            }
        }

        vector<string> ans;
        for (vector<int>& v1 : ranges) {
            bool f = true;
            for (vector<int>& v2 : ranges) {
                if (v1 == v2)
                    continue;
                if (v2[0] >= v1[0] && v2[1] <= v1[1]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                ans.push_back(s.substr(v1[0], v1[1] - v1[0] + 1));
            }
        }
        return ans;
    }
};