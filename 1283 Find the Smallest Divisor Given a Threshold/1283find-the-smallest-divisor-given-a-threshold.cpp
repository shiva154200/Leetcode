class Solution {
public:
    int calculateresult(vector<int>& nums, int t) {
        int r = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            r += ceil((double)nums[i] / t);
        }
        return r;  
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = h;

        while(l <= h) {
            int mid = (l + h) / 2;
            int result = calculateresult(nums, mid);

            if(result <= threshold) {
                ans = mid;      
                h = mid - 1;    
            } else {
                l = mid + 1;    
        }

   
    }
         return ans;
    }
};
