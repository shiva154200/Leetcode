class Solution {
public:
    int minSwaps(string s) {
        int ans=INT_MAX;
       
        char ch='1';
        int on=0;
        int z=0;
        for(char &c:s){
            if(ch!=c) {
            if(ch=='1')on++;
            else z++;
            }
            ch=(ch=='1')?'0':'1';
        }
        if(on==z) ans=on;
      on=0;z=0;
        ch='0';
         for(char &c:s){
            if(ch!=c) {
            if(ch=='1')on++;
            else z++;
            }
            ch=(ch=='1')?'0':'1';
        }
        if(on==z) ans=min(on,ans);

        if(ans==INT_MAX) return -1;
        return ans;

        
    }
};