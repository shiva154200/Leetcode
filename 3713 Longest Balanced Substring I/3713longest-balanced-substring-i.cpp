class Solution {
public:
  bool isbalenced(unordered_map<char,int>&mp,char &ch){
    int sz=mp[ch];

    for(auto &p:mp){
        if(p.second!=sz) return false;

    }
    return true;


  }

  
    int longestBalanced(string s) {

        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            char ch=s[i];
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(isbalenced(mp,ch)) ans=max(ans,j-i+1);
            }
  
        }

       return ans; 
    }
};