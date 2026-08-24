class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>mp;
         for(char ch:s){
            mp[ch]++;
        }
        for(char ch:t){
          if(mp.count(ch)){
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
            else return false;
        }
        return(mp.empty());

    }
};