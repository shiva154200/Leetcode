class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // filling nums2 elements at the end of nums 1;
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        int i = 0;
        int  j = m;
        while (j >= i && j < m + n) {
            if (nums1[i] <= nums1[j])
                i++;
            else {

                int l = j;
                while (l > i) {
                    swap(nums1[l], nums1[l - 1]);
                    l--;
                }
                i++;
                j++;
            }
        }
    }
};