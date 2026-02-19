class Solution {
public:
    int countBinarySubstrings(string s) {

        int n=s.size();
        int cur=1;

        int prev =0;
        int c=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) {
                c+=min(cur,prev);
                prev=cur;
                cur=1;
            }
            else cur++;
        }
         c+=min(cur,prev);

         return c;

        
    }
};