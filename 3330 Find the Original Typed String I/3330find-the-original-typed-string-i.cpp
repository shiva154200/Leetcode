class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        unordered_set<char>s;
           int c=1;
          char ch=word[0];
        for(int i=1;i<n;i++){
           if(ch==word[i]) c++;
           else ch=word[i];
          }
           
        
     
       
        return c;
    }
};