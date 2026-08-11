class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        int smn = sum;
        if (i == 1)
            smn += 1;
        unordered_set<int> st;
        st.insert(smn);
        while (i < nums.size()) {
            if (nums[i] == smn) {
                smn++;
                while (st.count(smn)) {
                    smn++;
                }
            } else if (nums[i] > smn) {
                st.insert(nums[i]);
            }

            i++;
        }

        return smn;
    }
};