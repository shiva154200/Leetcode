class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.size();
       sort(s.begin(),s.end()) ;
       int mv=0;
       int mc=0;
       int ch=s[0];
       int i=0; 
       int c=0;
       while(i<n){
        while(i<n&&s[i]==ch) {c++;
        i++;}
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            if(c>mv) mv=c;
        }
         else{
            if(c>mc) mc=c;
         }
       

         ch=s[i];
         c=0;
       }
       

     return mv+mc;   
    }
};