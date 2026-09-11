class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> v(10, 0);//keep track of digits count
     
        int uq = 0 ;//unique non zero
        for (int x : digits) {
            if (x && v[x] == 0) uq++;
            v[x]++;
        }

        int ans = 0;
        for (int i = 0; i < 10; i += 2) {
            if (v[i] == 0)
                continue;
            for (int j = 0; j < 10; j++) {
                if (v[j] == 0 || (j == i && v[i] < 2))
                    continue;
                int k = uq;
                if (i != j) {
                    if (v[i] < 2 && i)
                        k--;
                    if (v[j] < 2 && j)
                        k--;
                    if (k > 0)
                        ans += k;
                } else {
                    if (i && v[i] < 3)
                        k--;
                    if (k > 0)
                        ans += k;
                }
                
            }
        }

        return ans;
    }
};