class Solution {
public:
    int maximumLengthSubstring(string s) {

        unordered_map<char, int> mp;
        int mx=0;
        int st=0;
        for (int i = 0; i < s.size();i++){

            mp[s[i]]++;
            while(mp[s[i]]>2) {mp[s[st]]--;
            st++;}

            mx=max(mx,i-st+1);


        }

        return mx;

        }
    
};