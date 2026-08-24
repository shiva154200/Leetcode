class Solution {
public:
    int numSteps(string s) {

        int c=0;
        while (s.size()!=1){
            c++;
            if(s[s.size()-1]=='0') s.pop_back();
            else{
                int k=s.size()-1;
                while(k>=0&&s[k]=='1') {s[k]='0';k--;}
                if(k>=0) s[k]='1';
                else s='1'+s;
            }
        }

       return c; 
    }
};