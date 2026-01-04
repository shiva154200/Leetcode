// class Solution {
// public:
//     int minLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = n + 1;

//         int sum = 0;
//         int j = 0;
//         unordered_map<int, int> mp;

//         for (int i = 0; i < n; i++) {

//             if(!mp.count(nums[i])){
//                  sum += nums[i];
//             }
//             mp[nums[i]]++;

         
//             if (sum >= k) {
//                 int l = i - j + 1;
//                 while (j < i) {
//                     if (mp[nums[j]] > 1) {
//                         mp[nums[j]]--;
//                          if (sum >= k) {
//                             l--;
//                         }
                        
                        
                       
//                     } else {
//                         sum -= nums[j];
//                         if (sum >= k) {
//                             l--;
//                         }
//                         mp.erase(nums[j]);
//                     }
//                     j++;
                    
//                 }
//                 if (ans > l)
//                     ans = l;
//                 sum = nums[j];
//                 mp[nums[j]] = 1;
//             }
//         }

//         return ans==n+1?-1:ans;
//     }
// };

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;

        unordered_map<int,int> mp;
        int sum = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {

            if (mp[nums[i]] == 0) {
                sum += nums[i];
            }
            mp[nums[i]]++;

            while (sum >= k) {
                ans = min(ans, i - j + 1);

                mp[nums[j]]--;
                if (mp[nums[j]] == 0) {
                    sum -= nums[j];
                    mp.erase(nums[j]);
                }
                j++;
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};