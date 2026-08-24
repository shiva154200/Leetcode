class Solution {
public:
    int binaryGap(int n) {
        vector<bool>v(32,false);
       int k=31;
        while(n){
            if(n&1) v[k]=true;
            n=n>>1;
            k--;
        }
        int gap=0;
        int prev=-1;

        for(int i=0;i<32;i++){
            if(v[i]){
                if(prev!=-1){
                    gap=max(gap,i-prev);
                }
                prev=i;
                
            }
        }
        
       return gap; 

        
    }
};