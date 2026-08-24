class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();

        vector<int>A;
        vector<int>B;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int x:nums){
            if(x%3==1) A.push_back(x);
            if(x%3==2) B.push_back(x);
            sum+=x;
        }
        int as=A.size();
        int bs=B.size();
        if(sum%3==0) return sum;
        else if (sum%3==1){
            int x=INT_MAX;
            int y=INT_MAX;
            if(as) x=A[0];
            if(bs>=2) y=B[0]+B[1];
            return sum-min(x,y);
        }

            int x=INT_MAX;
            int y=INT_MAX;
            if(bs) x=B[0];
            if(as>=2) y=A[0]+A[1];
            return sum-min(x,y);
        
    }
};