class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
         for(char ch:magazine){
            mp[ch]++;
        }
        for(char ch:ransomNote){
            if(mp.count(ch)){
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
            else return false;
        }
        return true;
    }
};