class Solution {
public:
    int minLengthAfterRemovals(string s) {
       int n=s.size();
        int ca=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')ca++;
            
        }

        return abs(2*ca-n);
        
    }
};