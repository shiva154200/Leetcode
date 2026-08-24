class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int m=a.size();
        int n=b.size();
        int i=m-1,j=n-1;
        char c='0';

        while(i>=0&&j>=0){
         if(a[i]==b[j]){
            if(c=='1') {ans.push_back('1');
            c=a[i];}
            else{
                c=a[i];
                ans.push_back('0');
            }
         
         }
         else{
            if(c=='1') ans.push_back('0');
            else ans.push_back('1');
         }
         i--;j--;
        }
        while(i>=0){
            if(c==a[i]) ans.push_back('0');
            else {ans.push_back('1');c='0';}
            i--;

        }
        while(j>=0){
            if(c==b[j]) ans.push_back('0');
            else {ans.push_back('1');c='0';}
            j--;

        }
        if(c=='1') ans.push_back('1');
reverse(ans.begin(),ans.end());
return ans;
        
    }

};