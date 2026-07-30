class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        if(n>m) return -1;
        vector<int>lps(n,0);
        int p=0;int s=1;
        while(s<n){
            if(needle[s]==needle[p]){
                lps[s]=p+1;
                p++;
                s++;
            }
            else if(p==0) s++;
            else p=lps[p-1];
        }

        p=0;
        s=0;
        while(p<n&&s<m){
              if(haystack[s]==needle[p]){
                p++;
                s++;
            }
            else if(p==0) s++;
            else p=lps[p-1];

        }
        if(p==n) return s-n;
        else return -1;

        
    }
};