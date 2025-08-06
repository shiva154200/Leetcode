class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       int n=s.size();
       map<char,int>mp;
       for(int i=0;i<n;i++){
        mp[s[i]]++;
       }
       string ans;
       while(mp.size()){
        auto it=mp.rbegin();
        int ch=it->first;
        int f=it->second;
        if(f<=repeatLimit){
            int k=0;
            while(k<f){
                ans.push_back(ch);
                k++;
            }
            mp.erase(ch);
        }
        else{
            int k=0;
            while(k<repeatLimit){
                ans.push_back(ch);
                k++;
            }
            f-=repeatLimit;
            mp.erase(ch);
            if(!mp.size()) return ans;
            ans.push_back(mp.rbegin()->first);
            mp.rbegin()->second-=1;
            if(mp.rbegin()->second==0){
                char d=mp.rbegin()->first;
                mp.erase(d);
            }

            mp[ch]=f;
        }

       }

       return ans;
    }
};