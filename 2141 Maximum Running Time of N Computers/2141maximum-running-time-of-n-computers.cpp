class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0;
        long long high = 0;
        
        for (int b : batteries) {
            high += b;
        }
        high /= n;

        while (low < high) {
            long long mid = (low + high + 1) / 2;

            long long total = 0;
            for (int b : batteries) {
                total += min((long long)b, mid);
            }

            if (total >= (long long)n * mid) {
                low = mid;   // possible
            } else {
                high = mid - 1; // not possible
            }
        }

        return low;
    }
};