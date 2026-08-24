class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int c=0;
        int m=1;
        while(n>8){
            c+=m*8;
            n-=8;
            m+=1;

        }
        c+=m*n;
        return c;

     
        
    }
};