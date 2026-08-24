class Solution {
public:
    bool checkOnesSegment(string s) {

        bool f=true;
        int c=0;
        for(char ch:s){
            if(ch=='1') {
              if(f) c++;
              f=false;

                }
            else{
                
                f=true;
            }

        }
  if(c>1) return false;
  return true;

        
    }
};