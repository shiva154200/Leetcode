class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        int mx=0;   int rl;  int cl;
          int mid,l,h;
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
            
             l=1;
             h=min(m-i,n-j);
             
             while(l<=h){

              mid=(l+h)/2;
              cl=j+mid-1;
              rl=i+mid-1;
              int sum=0;
              for(int p=i;p<=rl&&sum<=threshold;p++){
                sum+=(j>0?mat[p][cl]-mat[p][j-1]:mat[p][cl]);

              }
              if(sum<=threshold) {
                mx=max(mx,mid);
                l=mid+1;
              }
              else{
                h=mid-1;
              }

             }

           
            }
        }
        return mx;
        
    }
};