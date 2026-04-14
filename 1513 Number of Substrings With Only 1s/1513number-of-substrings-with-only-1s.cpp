class Solution {
public:
int mod=1e9+7;
    int numSub(string s) {
        long long ans=0;
        long long n=0;
        for(char c : s){
    if(c == '1'){
        n++;
        ans = (ans + n) % mod;
    } else {
        n = 0;
    }
}
        
        
     return ans;   
    }
};