class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        int q=1;
        vector<int>v(n,0);


        for(int i=0;i<n;i++){
            if(nums[i]<0) {
                v[q]=nums[i];
                q+=2;
            }
            else{
                v[p]=nums[i];
                p+=2;
            }
        }

        return v;
        
    }
};