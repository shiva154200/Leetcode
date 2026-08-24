class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) ans += "-";

        // Convert to long long to avoid overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        ans += to_string(n / d);
        n %= d;
        if (n == 0) return ans;

        ans += ".";
        unordered_map<long long, int> mp;
        string frac = "";

        while (n) {
            if (mp.count(n)) {
                frac.insert(mp[n], "(");
                frac.push_back(')');
                break;
            }
            mp[n] = frac.size();
            n *= 10;
            frac.push_back('0' + n / d);
            n %= d;
        }

        return ans + frac;
    }
};

      

         

