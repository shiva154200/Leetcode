class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> v;
        v.push_back(INT_MIN);

        for (int x : nums) {
            if (v[v.size() - 1] < x)
                v.push_back(x);
            else if( v[v.size()-1]==x) continue;
            else {

                int l = 0;
                int h = v.size() - 1;
                int mid;

                while (l <= h) {

                    mid = (l + h) / 2;

                    if (v[mid] < x)
                        l = mid + 1;
                    else
                        h = mid - 1;
                }
                v[l] = x;
            }
        }
        return v.size() - 1;
    }
};