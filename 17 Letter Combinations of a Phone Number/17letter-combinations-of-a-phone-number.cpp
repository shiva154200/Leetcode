class Solution {
public:
    void helper(string &digits,int i,vector<string>&letters, vector<string>&ans,string &s){
        if(digits.size()==i){
            ans.push_back(s);
            return;
        }

            int d=(digits[i]-48);
            string ltr=letters[d];
         
            for(int j=0;j<ltr.size();j++){
                s.push_back(ltr[j]);
                helper(digits,i+1,letters,ans,s);
                s.pop_back();
            }
        


    }
    vector<string> letterCombinations(string digits) {
        vector<string>letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string s="";
        helper(digits,0,letters,ans,s);
        return ans;
        
    }
};