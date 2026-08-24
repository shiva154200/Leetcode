class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        char ch = 'a';
        char t = ch;
        double r = 1;
        while (k != 0) {
            t = ch;
              int i;
            for ( i = 0; i < n&&r*2<=k; i++) {
                r*=2;
                if(operations[i]) {
                    if(t=='z') t='a';
                   else t=(char)(t+1);
                    }

            }
            if(r==k) return t;
            if(operations[i]) {
                    if(ch=='z') ch='a';
                   else ch=(char)(ch+1);
                    }
            k=k-r;
            r=1;
            
        }
        return ch;

    }
};