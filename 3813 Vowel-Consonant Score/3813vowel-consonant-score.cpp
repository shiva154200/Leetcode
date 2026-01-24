class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_set<int> st;
        for (char c : "aeiou") {
            st.insert(c);
        }
        int v = 0, c = 0;

        for (char ch : s) {
            if (st.count(ch))
                v++;
            else if (ch >= 97 && ch <= 122)
                c++;
        }
        if (c > 0)
            return v / c;
        return 0;
    }
};