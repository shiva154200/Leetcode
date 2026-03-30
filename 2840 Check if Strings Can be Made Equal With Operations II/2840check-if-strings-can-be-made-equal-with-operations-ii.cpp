class Solution {
public:
    bool checkStrings(string s1, string s2) {
      
        int n = s2.size();
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;

        for (int i = 0; i < n; i++) {
            
            if (i % 2)
                mp1[s1[i]]++;
            else
                mp[s1[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (i % 2) {
                if (mp1.count(s2[i])){
                        mp1[s2[i]]--;
                        if (mp1[s2[i]] == 0)
                            mp1.erase(s2[i]);
                    }
                else
                    return false;
            } 
            else {
                 if (mp.count(s2[i])){
                        mp[s2[i]]--;
                        if (mp[s2[i]] == 0)
                            mp.erase(s2[i]);
                    }
                else
                    return false;
            }
        }

        return true;
    }
};