class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int z=INT_MAX;
        vector<vector<int>>matrix(26,vector<int>(26,z));
        int n=original.size();
        
        for(int i=0;i<26;i++){
            matrix[i][i]=0;
        }

        int r,c;

        for(int i=0;i<n;i++){
            r=original[i]-97;
            c=changed[i]-97;
            matrix[r][c]=min(cost[i],matrix[r][c]) ;
        }


        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
            
              
                for(int j=0;j<26;j++){
                    if (matrix[i][k]==z||matrix[k][j]==z) continue;
              
                   matrix[i][j]=min(matrix[i][k]+matrix[k][j],matrix[i][j]);

                }

            }
        }

        long long ans=0;

        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            int ad=matrix[source[i]-97][target[i]-97];
            if(ad==z) return -1;
            ans+=ad;
        }
        
        return ans;
    }
};