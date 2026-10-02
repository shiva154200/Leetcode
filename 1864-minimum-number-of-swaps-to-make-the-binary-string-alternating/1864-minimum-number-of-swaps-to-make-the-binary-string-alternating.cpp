class Solution {
public:
    int minSwaps(string s) {
        int ans=INT_MAX;
        int x=0;
        int ones=0;
        int zeros=0;
        char ch='1';
        for(char &c:s){
            if(ch!=c) x++;
            ch=(ch=='1')?'0':'1';

            if(c=='1') ones++;
            else zeros++;
        }

        if(abs(ones-zeros)>1) return -1;
        if(x%2==0) ans=x/2;
        x=0;
        ch='0';
         for(char &c:s){
            if(ch!=c) x++;
            ch=(ch=='1')?'0':'1';
        }
        if(x%2==0) ans=min(x/2,ans);

    
        return ans;

        
    }
};