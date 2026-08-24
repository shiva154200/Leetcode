class Solution {
public:
    // long long helper(vector<int>& nums){
    //     int n=nums.size();
    //     long long ans=0;
    //     for(int i=0;i<n-1;i++){
    //       for(int j=i+1;j<n;j++){
    //         ans+=(j-i);
    //       }
    //     }
    //     return ans;
    // }
 vector<long long> distance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size();
    vector<long long> ans(n, 0);

   
    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

  
    for (auto &p : mp) {
        auto &v = p.second;
        int k = v.size();

        vector<long long> prefix(k, 0);

     
        prefix[0] = v[0];
        for (int i = 1; i < k; i++) {
            prefix[i] = prefix[i - 1] + v[i];
        }

        for (int i = 0; i < k; i++) {
            long long left = 0, right = 0;

          
            if (i > 0) {
                left = (long long)v[i] * i - prefix[i - 1];
            }

         
            if (i < k - 1) {
                right = (prefix[k - 1] - prefix[i]) - (long long)v[i] * (k - i - 1);
            }

            ans[v[i]] = left + right;
        }
    }

    return ans;
}
};