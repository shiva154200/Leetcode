class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int>closingbrackets;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                closingbrackets.push_back(ans.size());

            }
            else if(s[i]==')'){
                int idx=closingbrackets.back();
                closingbrackets.pop_back();
                reverse(ans.begin()+idx,ans.end());
            }
            else{
                ans.push_back(s[i]);
            }


        }

        return ans;
        
    }
};