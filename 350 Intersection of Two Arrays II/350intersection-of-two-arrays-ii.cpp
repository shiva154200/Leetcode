class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        for (int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]]++;
        }
        unordered_map<int, int> mp2;
        for (int i = 0; i < nums2.size(); i++) {
            mp2[nums2[i]]++;
        }
        vector<int> ans;
        for (auto& [key, value] : mp1) {

            if (mp2.count(key)) {
                int k = min(value, mp2[key]);
                for (int i = 0; i < k; i++) {
                    ans.push_back(key);
                }
            }
        }

        return ans;
    }
};