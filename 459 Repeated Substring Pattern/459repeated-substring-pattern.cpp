class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
       
        vector<int>lps(s.size(),0);
        int pf=0;int sf=1;
        while(sf<s.size()){
            if(s[pf]==s[sf]){
                lps[sf]=pf+1;
                pf++;
                sf++;
            }
            else if(pf==0) sf++;
            else {
                pf=lps[pf-1];
            }
        }

    //  /   for(int x:lps) cout<<x<<" ";
        
       int d=lps.size()-lps.back();
        
        if(!lps.back()||lps.back()%d) return false;
        // int i=d;
        // int k=0;
        // while(k<d&&i<s.size()){
        //     if(s[k]!=s[i]) return false;
        //     k++;
        //     i++;
        // }
        // if(k!=d) return false;
        return true;

    }
};