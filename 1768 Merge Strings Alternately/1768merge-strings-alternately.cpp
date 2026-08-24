class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int i=0;
        
        string s="";
        while(i<m&&i<n){
            s.push_back(word1[i]);
            s.push_back(word2[i]);
            i++;
        }
         while(i<m){
            s.push_back(word1[i]);
            
            i++;
        }
         while(i<n){
           
            s.push_back(word2[i]);
            i++;
        }

        return s;
        
    }
};