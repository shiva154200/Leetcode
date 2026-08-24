class Solution {
public:
    int f[10][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {2,0,0,0},
        {0,0,1,0},
        {1,1,0,0},
        {0,0,0,1},
        {3,0,0,0},
        {0,2,0,0}
    };

    vector<int> factor(long long t) {
        vector<int> cnt(4, 0);

        for (int i = 0; i < 4; i++) {
            int p = (int[]){2,3,5,7}[i];

            while (t % p == 0) {
                cnt[i]++;
                t /= p;
            }
        }

        if (t != 1) return {};

        return cnt;
    }

    vector<int> factorString(const string &s) {
        vector<int> cnt(4, 0);

        for (char c : s) {
            for (int j = 0; j < 4; j++)
                cnt[j] += f[c - '0'][j];
        }

        return cnt;
    }

    vector<int> subtract(vector<int> a, const vector<int> &b) {
        for (int i = 0; i < 4; i++)
            a[i] = max(0, a[i] - b[i]);

        return a;
    }

    vector<int> makeDigits(vector<int> cnt) {
        vector<int> res(8, 0);

        int c8 = cnt[0] / 3;
        int r2 = cnt[0] % 3;

        int c9 = cnt[1] / 2;
        int r3 = cnt[1] % 2;

        int c4 = r2 / 2;
        int r = r2 % 2;

        int c6 = 0;

        if (r == 1 && r3 == 1) {
            r = 0;
            r3 = 0;
            c6 = 1;
        }

        if (r3 == 1 && c4 == 1) {
            r = 1;
            c4 = 0;
            r3 = 0;
            c6 = 1;
        }

        res[0] = r;
        res[1] = r3;
        res[2] = c4;
        res[3] = cnt[2];
        res[4] = c6;
        res[5] = cnt[3];
        res[6] = c8;
        res[7] = c9;

        return res;
    }

    int size(vector<int> &v) {
        int ans = 0;

        for (int x : v)
            ans += x;

        return ans;
    }

    string build(vector<int> &cnt) {
        string ans;

        for (int d = 2; d <= 9; d++)
            ans += string(cnt[d - 2], '0' + d);

        return ans;
    }

    string smallestNumber(string num, long long t) {
        vector<int> need = factor(t);

        if (need.empty() && t != 1)
            return "-1";

        vector<int> minDigits = makeDigits(need);

        if (size(minDigits) > num.size())
            return build(minDigits);

        vector<int> cur = factorString(num);

        int firstZero = num.find('0');

        if (firstZero == string::npos) {
            firstZero = num.size();

            bool ok = true;

            for (int i = 0; i < 4; i++) {
                if (cur[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }

        for (int i = num.size() - 1; i >= 0; i--) {
            int d = num[i] - '0';

            cur = subtract(cur, vector<int>(f[d], f[d] + 4));

            int space = num.size() - 1 - i;

            if (i > firstZero)
                continue;

            for (int nd = d + 1; nd <= 9; nd++) {
                vector<int> req = subtract(need, cur);

                req = subtract(req, vector<int>(f[nd], f[nd] + 4));

                vector<int> digits = makeDigits(req);

                if (size(digits) <= space) {
                    string ans = num.substr(0, i);

                    ans += char('0' + nd);

                    ans += string(space - size(digits), '1');

                    ans += build(digits);

                    return ans;
                }
            }
        }

        vector<int> digits = makeDigits(need);

        return string(num.size() + 1 - size(digits), '1') +
               build(digits);
    }
};