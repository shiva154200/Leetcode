class Solution {
public:
    bool checkZeroOnes(string s) {
        int zmx=0;
        int onmx=0;
        int ct=1;
        
     

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                ct++;
            }
            else if(s[i-1]=='0') {
                zmx=max(zmx,ct);
                ct=1;
            
            }
            else{
                onmx=max(onmx,ct);
                ct=1;
            }
        }
          cout<<onmx<<" "<<zmx;
          if(s.back()=='0') {
                zmx=max(zmx,ct);
                ct=1;
            
            }
            else{
                onmx=max(onmx,ct);
                ct=1;
            }

    return(onmx>zmx);
    }
};