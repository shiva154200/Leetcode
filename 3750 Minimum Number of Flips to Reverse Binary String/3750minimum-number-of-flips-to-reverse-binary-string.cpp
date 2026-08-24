class Solution {
public:
    int minimumFlips(int n) {
        // build binary string without leading zeros
        string s;
        if (n == 0) s = "0";
        else {
            while (n > 0) {
                s.push_back((n & 1) + '0');
                n >>= 1;
            }
            reverse(s.begin(), s.end());
        }

        int l = 0, r = (int)s.size() - 1;
        int mismatched_pairs = 0;
        while (l < r) {
            if (s[l] != s[r]) mismatched_pairs++;
            l++; r--;
        }
        return 2 * mismatched_pairs;
    }
};

