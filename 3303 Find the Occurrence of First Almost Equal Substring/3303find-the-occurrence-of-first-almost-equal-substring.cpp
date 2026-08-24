class Solution {
public:
    vector<int> zFunction(const string& s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();

        vector<int> left = zFunction(pattern + s);

        reverse(pattern.begin(), pattern.end());
        reverse(s.begin(), s.end());

        vector<int> right = zFunction(pattern + s);

        for (int i = 0; i + m <= n; i++) {
            int pref = left[m + i];
            int suff = right[n - i];

            if (pref + suff >= m - 1)
                return i;
        }

        return -1;
    }
};