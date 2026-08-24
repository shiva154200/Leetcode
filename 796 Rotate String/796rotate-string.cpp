class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        s+=s;
          vector<int>lps(goal.size(),0); 
        int pre=0;
     int suf=1;
     while(suf<goal.size()){
            if(goal[suf]==goal[pre]){
                
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else if(pre==0) {
                suf++;}
            else pre=lps[pre-1];
        }

     pre=0;
     suf=0;
     while(suf<s.size()&&pre<goal.size()){
            if(goal[pre]==s[suf]){
                
                pre++;
                suf++;
            }
            else if(pre==0) {
                suf++;}
            else pre=lps[pre-1];
        }
    if(pre==goal.size()) return true;
    return false;

        
        
    }
};