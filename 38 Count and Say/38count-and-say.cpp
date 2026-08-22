class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        string ans="";
        int c=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) c++;
            else{
                ans+=to_string(c);
                ans.push_back(s[i-1]);
                c=1; 
            }
        }
         ans+=to_string(c);
        ans.push_back(s[s.size()-1]);

        return ans;
        
    }
};