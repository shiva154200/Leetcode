class Solution {
public:
    int reverse(int x) {
        long rev = 0; // use long to detect overflow
        
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        
        // Check for 32-bit overflow
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;
        
        return (int)rev;
    }
};
