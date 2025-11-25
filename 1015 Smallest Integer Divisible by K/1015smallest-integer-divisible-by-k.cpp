class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k%2||k%5)) return -1;

       int l=1;
       int rem=0;
       while(l<=k){

        rem=(rem*10+1)%k;

        if(rem==0) return l;
        l++;


       }

        return -1;

        
     
    
     

       





        
        
        


    }
};