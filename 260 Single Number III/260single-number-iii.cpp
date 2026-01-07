class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int c=0;
        int n =nums.size();

        for(int i=0;i<n;i++){
            c=c^nums[i];
        }
        int s=0;
        while(  !((c>>s)&1)  ) s++;
        int t=0;
        for(int i=0;i<n;i++){
            if((nums[i]>>s)&1) t=t^nums[i];
        }

        vector<int>ans;
        ans.push_back(t);
        ans.push_back(c^t);

        return ans;

        
        
    }
};