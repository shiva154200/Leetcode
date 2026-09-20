class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int idx = 1;
        for (char& c : s) {
            ans += (idx * (123 - c));
            idx++;
        }
        return ans;
    }
};