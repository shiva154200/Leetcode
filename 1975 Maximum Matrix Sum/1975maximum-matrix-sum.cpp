class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ans = 0;
        int sm=INT_MAX;
        int c=0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                ans+=abs(matrix[i][j]);

                if( sm > abs(matrix[i][j])) sm=abs(matrix[i][j]);
                if(matrix[i][j]<0) c++;


            }

        }

        if(c%2==0) return ans;
        return ans-2*sm;

    }
};