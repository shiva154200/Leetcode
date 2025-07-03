class Solution {
public:
    char kthCharacter(int k) {
        if (k==1) return 'a';

        char ch='a';
        char t='a';
        int i=1;
        while(1){
            i=1;
            t=ch;
            while(i*2<=k){
            i*=2;
            if(t=='z') t=='a';
            else t=char(t+1);
        }
        if(i==k) return t;
        k=k-i;
        ch=char(ch+1);
        }
        return ch;
       
     

        
        
        
    }
};