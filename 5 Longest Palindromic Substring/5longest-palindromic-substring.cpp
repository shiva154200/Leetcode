class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,vector<int>>mp;
 
        for(int i=0;i<n;i++){
               mp[s[i]].push_back(i);
        }
        string ans;
        ans.push_back(s[0]);
        for(int i=0;i<n;i++){

            if(mp[s[i]].size()>1)
            {
                int l=mp[s[i]].size();
                for(int j=l-1;mp[s[i]][j]>i;j--){
                    int k=mp[s[i]][j];
                   string t = s.substr(i, k - i + 1);
                   string r=t;
                   reverse(t.begin(), t.end());
                if(r==t){
                    if(r.size()>ans.size()) ans=r;
                    break;
                }
                }

            }
        }
      return ans;  
    }
};