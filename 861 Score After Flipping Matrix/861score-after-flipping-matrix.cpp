class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>v(n,0);
        for(int i=0;i<m;i++){
            bool f=true;
            if(grid[i][0]) f=false;
            for(int j=0;j<n;j++){
              if(f)grid[i][j]=abs(grid[i][j]-1);
              if(grid[i][j]==0) v[j]++;
            }
        }
        int ans=0;
       int k=1;
       
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";

        //     }
        //     cout<<endl;
        // }

        // for(int x:v) cout<<x<<" ";

        for(int i=n-1;i>=0;i--){
            ans+=k*max(v[i],m-v[i]);
            k<<=1;


        }

        return ans;


        
    }
};