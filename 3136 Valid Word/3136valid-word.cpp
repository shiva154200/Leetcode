class Solution {
public:
   bool isnum(int n){
    if(n<58&&n>47) return true;
    return false;
   }
   bool isalpha(int n){
    if((n<=90&&n>=65)||(n<=123&&n>=97)) return true;
    return false;
   }
    bool isValid(string &s) {
      
        int n=s.length();
        if(n<3) return false;
        
       
      
        bool vp=0;
        bool cp=0;

        for(int i=0;i<n;i++){
             if(isnum(s[i])) continue;
             if(isalpha(s[i])){
                if(s[i]<91) s[i]=char(s[i]+32);
                int ch=s[i];
               if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') vp=1;
               else cp=1;
             }
             else return false;
            }

            if(vp&&cp) return true;
            return false;


        
    }
};