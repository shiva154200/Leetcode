class Solution {
public:
    long long countCommas(long long n) {
        //shiv
        if (n < 1000)
            return 0;
        int m = 1000;
        long long t = 999;
        long long ans = 0;
        long long z = 999;
        int d = 0;
        while (n > z) {

            ans += t * d;
            t *= 1000;
            z += t;

            d++;
        }
        z -= t;
        cout << z;
        ans += ((n - z) * d);
        return ans;
    }
};