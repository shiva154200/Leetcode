class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s=strs[0];
        string l=strs[strs.size()-1];
        string ans="";
        int i=0;
        int j=0;
        while(i<s.size()&&j<l.size()&&s[i]==l[i]){
            ans+=s[i];
            i++;j++;
        } 

        return ans;
        
    }
};