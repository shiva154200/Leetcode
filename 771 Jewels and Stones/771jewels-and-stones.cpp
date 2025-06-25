class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>s;
        for(char ch:jewels){
            s.insert(ch);
        }
        int c=0;
         for(char ch:stones){
           if(s.count(ch)) c++;
        }
        return c;
    }
};