class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(!s.length()) return 0;

        unordered_map<char,int>mp;
        int ans=0;
        int c=0;
        int st=0;
        for(int i=0;i<s.size();i++){

            if(mp.count(s[i])&&mp[s[i]]>=st){
                ans=max(ans,c);
                c=i-mp[s[i]];  
                st=mp[s[i]]+1;
               
            }
            else c++;

            mp[s[i]]=i;

        }

        ans=max(ans,c);

        return ans;


        
    }
};