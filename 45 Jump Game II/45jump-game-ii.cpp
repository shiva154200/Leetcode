class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> p(n, n);
        p[0] = 0;

        for (int i = 0; i < n; i++) {
           
                int t = nums[i];
                int z=p[i]+1;
                for (int j = i + 1; j < n && t; j++) {
                    p[j] = min(p[j],z);
                    t--;
                }
            
            }

            return p[n-1];
        
    }
    };