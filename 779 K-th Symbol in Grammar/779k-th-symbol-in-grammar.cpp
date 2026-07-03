class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1&&k==1) return 0;
        int c=kthGrammar( n-1,  (k+1)/2);
        if(k%2) return c;
        if(c==1) return 0;
        return 1;
        
    }
};