class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for (int i = 0; i < n; i++) {
            int k = -1;
            for (int j = 0; j < m; j++) {
                if (boxGrid[i][j] == '*') {
                    int r = j - 1;
                    int t = j - 1;
                    while (t > k) {
                        if (boxGrid[i][t] == '#') {
                            boxGrid[i][t]='.';
                            boxGrid[i][r] = '#';
                            r--;
                        }
                        t--;
                    }
                    k = j;
                }
            }

            int r = m - 1;
            int t = m - 1;
            while (t > k) {
                if (boxGrid[i][t] == '#') {
                     boxGrid[i][t] = '.';

                    boxGrid[i][r] = '#';
                    r--;
                }
                t--;
            }
        }
        // cout<<endl<<"[";
        //  for(int i=0;i<n;i++){
        //     cout<<"[";
        //     for(int j=0;j<m;j++){
        //         cout<<boxGrid[i][j]<<",";
        //     }
        //      cout<<"] ,";}
        //      cout<<']'<<endl;
        vector<vector<char>>ans(m,vector<char>(n,'.'));
          int k=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                ans[j][k]=boxGrid[i][j];

            }
            k--;
        }

        return ans;
    }
};