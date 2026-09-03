class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool allodd = true;
        bool allevn = true;
        int minodd = INT_MAX;
        int minevn = INT_MAX - 1;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2) {
                if (minodd > nums1[i]) {
                    minodd = nums1[i];
                }

                allevn = false;
            } else {

                if (minevn > nums1[i]) {
                    minevn = nums1[i];
                }

                allodd = false;
            }
        }

        if (allevn || allodd)
            return true;
        if (minevn > minodd)
            return true;
        return false;
    }
};