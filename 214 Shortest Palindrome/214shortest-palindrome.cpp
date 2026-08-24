class Solution {
public:
    string shortestPalindrome(string s) {

    string  rev=s;
    reverse(rev.begin(),rev.end());
     string r=s+"#"+rev;
     vector<int>lps(r.size(),0);

     int pre=0;
     int suf=1;
     while(suf<r.size()){
            if(r[suf]==r[pre]){
                
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else if(pre==0) {
                suf++;}
            else pre=lps[pre-1];
        }
        int len = lps.back();

        return rev.substr(0, s.size() - len) + s;

    



    
        
    }
};