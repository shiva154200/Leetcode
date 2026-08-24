class Solution {
public:
    bool checkDivisibility(int n) {

        string s=to_string(n);
        int sm=0;
        int m=1;
        for(char c:s){
            sm+=(c-48);
            m*=(c-48);
        }

        if(n%(sm+m)) return false;
        return true;
        
    }
};