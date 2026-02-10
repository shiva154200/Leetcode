class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if(evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int longestBalanced(vector<int>& nums) {
//         unordered_map<int,int> firstIndex;
//         unordered_map<int,int> lastSeen;

//         int distinctEven = 0, distinctOdd = 0;
//         int diff = 0;
//         int ans = 0;

//         firstIndex[0] = -1;   

//         for(int i = 0; i < nums.size(); i++) {

           
//             if(!lastSeen.count(nums[i])) {
//                 if(nums[i] % 2 == 0) distinctEven++;
//                 else distinctOdd++;
//             }

//             lastSeen[nums[i]] = i;

//             diff = distinctEven - distinctOdd;

//             if(firstIndex.count(diff)) {
//                 ans = max(ans, i - firstIndex[diff]);
//             } else {
//                 firstIndex[diff] = i;
//             }
//         }

//         return ans;
//     }
// };
