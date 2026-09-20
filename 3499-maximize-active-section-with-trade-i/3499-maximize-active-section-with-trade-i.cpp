class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int stz = 0; //number of starting zeros
        int mdn = 0; //number of middle ones
        int enz = 0;//number of ending zeros
        int ans = 0; //ans stores selected window size for opration
        int preons = 0;//previous window ones
        int si = -1;//selected windows starting index
        int ei = -1; //selected windows ending index

        // stz   mdn   enz
        //     |     |
        // 0000111111100000


        for (int i = 0; i < n; i++) {
         
            if (s[i] == '1' && enz) {
                
                if (ans == 0 || ((stz + mdn + enz + preons) > (ans + mdn))) {
                    ans = stz + mdn + enz;
                    si = i - ans;
                    ei = i - 1;
                    preons = mdn;
                } 
                stz = enz;
                mdn = 1;
                enz = 0;

            } else if (s[i] == '1' && stz) {
                mdn++;
            } else if (s[i] == '0' && mdn) {
                enz++;
            } else if (s[i] == '0') {
                stz++;
            }
        }

        if (enz) {
          
                if (ans == 0 || ((stz + mdn + enz + preons) > (ans + mdn))) {

                    ans = stz + mdn + enz;
                    si = n - ans;
                    ei = n - 1;
                    preons = mdn;
                }
        }

        cout << si << " " << ei;
        int finalans = 0;
        int i = 0;
        while (i < n) {
            if (i == si) {
                i = ei + 1;
            } else if (s[i] == '1') {
                finalans++;
                i++;
            } else
                i++;
        }
        return finalans + ans;
    }
};