class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { int n = nums1.size() + nums2.size();
        int i = 0, j = 0;
        double p = 0, p1 = 0;
        int k = 0;

        while (k <= n / 2) {
            p = p1;
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
                p1 = nums1[i];
                i++;
            } else {
                p1 = nums2[j];
                j++;
            }
            k++;
        }

        if (n % 2 == 0) {
            return (p + p1) / 2.0;
        } else {
            return p1;
        }
    }
};