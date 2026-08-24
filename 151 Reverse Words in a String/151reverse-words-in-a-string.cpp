class Solution {
public:


    string reverseWords(string s) {
        int n=s.size();
        int j=n-1;
        string ans="";
    

        while(j>=0){

        while(j>=0&&s[j]==' ') j--;
        if(j<0) break;

        int l=j;
         while(j>=0&&s[j]!=' ') j--;


         ans+=s.substr(j+1,l-j)+" ";
          

        }
        

        return ans.substr(0,ans.size()-1);

        

    }
};