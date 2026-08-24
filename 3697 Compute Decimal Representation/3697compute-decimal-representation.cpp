class Solution {
public:
    vector<int> decimalRepresentation(int n) {
         string s=to_string(n);
         int sz=s.size();
         long long m=1;
         vector<int>ans;

         for(int i=sz-1;i>=0;i--){
            char ch=s[i];
            if(ch!='0') {
                ans.push_back((ch-48)*m);
                }
                m*=10;
         }

         reverse(ans.begin(),ans.end());
         return ans;
        
    }
};