class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mx = 0;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            v[i] = mx;
            if (mx < height[i])
                mx = height[i];
        }
        mx = 0;
        int ans=0;
        for (int i = n - 1; i >= 0; i--) {
            if (min(mx, v[i]) > height[i])
                ans +=  min(mx, v[i])-(height[i] );
            if (mx < height[i])
                mx = height[i];
        }

        return ans;
    }
};