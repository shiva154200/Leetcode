class Solution {
public:
    void helper( vector<string>&ans,string &s,int o,int c,int n){
        if(o==n&&c==n){
            ans.push_back(s);
            return;
        }
        if(o<n){
            s.push_back('(');
            helper(ans,s,o+1,c,n);
            s.pop_back();
        } 
         if(o>c){
            s.push_back(')');
            helper(ans,s,o,c+1,n);
            s.pop_back();
        } 
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>ans;
        helper(ans,s,0,0,n);
        return ans;


        
    }
};