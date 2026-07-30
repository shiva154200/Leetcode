class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        vector<int>lps(b.size(),0);
        int pf=0;
        int sf=1;
          while(sf<b.size()){
            if(b[pf]==b[sf]){
                lps[sf]=pf+1;
                pf++;
                sf++;
            }
            else if(pf==0) sf++;
            else {
                pf=lps[pf-1];
            }
        }

        pf=0;
        sf=0;
        int k=b.size()/a.size()+3;
        int c=1;
        while(pf<b.size()&& c<k){
            if(sf>=a.size()) {sf=0;c++;}
            if(a[sf]==b[pf]){
                pf++;
                sf+=1;
            }
            else if(pf) {
                pf=lps[pf-1];
            }
            else sf++;
            
           
            
        }
        if(pf==b.size()) return c;
        return -1;
        


        
    }
};