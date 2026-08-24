class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
       for(int i=1;i<words.size();i++){
        string s=words[i];
        sort(s.begin(),s.end());
        string p=words[i-1];
        sort(p.begin(),p.end());
        if(s==p) continue;
        ans.push_back(words[i]);
       }
       return ans;
    }
};