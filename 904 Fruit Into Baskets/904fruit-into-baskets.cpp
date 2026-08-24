class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int f1=fruits[0];

        int i=0;
        while(i<n&&fruits[i]==f1) i++;
        if(i==n) return n;
        int f2=fruits[i];
     
        int count=0;
        int c=i;
        int c1=0;
        int c2=1;
   
        while(i<n){
      
            while(i<n&&(fruits[i]==f1||fruits[i]==f2)) {
               
          

             if(fruits[i]==f1){
                c2=0;
              if(fruits[i-1]==f1) c1++;
              else c1=1;
             }
              if(fruits[i]==f2){
                c1=0;
            if(fruits[i-1]==f2) c2++;
            else c2=1;
             }
             c++;
             i++;


            }
            if(i==n){
                if(count<c) count=c;
                return count;
            }
            else{
            if(count<c) count=c;
               int d;
               if(fruits[i-1]==f1){
                d=c1;
               }
               else d=c2;
              f1=fruits[i-1];
               f2=fruits[i];
               c1=0;c2=1;
               c=d+1;
               i++;
               

            }
       
        }
         if(count<c) count=c;
         return count;

        
    }
};