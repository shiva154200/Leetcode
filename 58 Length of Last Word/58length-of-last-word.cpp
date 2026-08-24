class Solution {
public:
    int lengthOfLastWord(string s) {
        int ct=0;
        int j=s.size()-1;
        while(s[j]==' ') j--;
        while(j>=0&&s[j]!=' '){
            ct++;
            j--;
        }
       
        return ct;
        
    }
};