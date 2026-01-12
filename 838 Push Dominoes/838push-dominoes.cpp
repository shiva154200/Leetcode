class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string s = "L" + dominoes + "R";
        string ans = s;

        int i = 0;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == '.') continue;

            if (j - i > 1) {
                if (s[i] == s[j]) {
                    for (int k = i + 1; k < j; k++)
                        ans[k] = s[i];
                }
                else if (s[i] == 'R' && s[j] == 'L') {
                    int l = i + 1, r = j - 1;
                    while (l < r) {
                        ans[l++] = 'R';
                        ans[r--] = 'L';
                    }
                }
            }
            i = j;
        }

        return ans.substr(1, n);
    }
};
