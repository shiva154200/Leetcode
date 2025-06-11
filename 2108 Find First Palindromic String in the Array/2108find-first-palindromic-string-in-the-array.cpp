class Solution {
public:
    bool ispalindrome(string s){
       
        for(int i=0 ,j=s.length()-1;i<j;i++,j--){
            if(s[i]!=s[j]) {
                return false;
               
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(ispalindrome(words[i])){
                return words[i];
            }
        }
        return "";
        
    }
};