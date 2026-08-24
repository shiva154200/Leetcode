class Solution {
public:
    bool closeStrings(string words1, string words2) {
        if (words1.length() != words2.length())
            return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;

        for (int i = 0; i < words1.length(); i++) {
            mp[words1[i]]++;
        }

        for (int i = 0; i < words2.length(); i++) {
            mp1[words2[i]]++;
        }
        unordered_set<char> s1, s2;
        for (auto x : mp)
            s1.insert(x.first);
        for (auto x : mp1)
            s2.insert(x.first);
        if (s1 != s2)
            return false;
        unordered_map<int, int> helper;
        for (auto x : mp) {
            helper[x.second]++;
        }
        unordered_map<int, int> helper1;
        for (auto x : mp1) {
            helper1[x.second]++;
        }

        for (auto x : helper) {
            if (!helper1.count(x.first))
                return false;
            if (x.second != helper1[x.first])
                return false;
        }
        return true;
    }
};