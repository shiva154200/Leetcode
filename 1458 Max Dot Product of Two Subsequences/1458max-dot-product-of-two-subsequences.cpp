class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int x=nums1[i]*nums2[j];
                dp[i][j]=x;
                if(i>0&&j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+x);
                if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
                
            }
        }
        return dp[m-1][n-1];
    }
};