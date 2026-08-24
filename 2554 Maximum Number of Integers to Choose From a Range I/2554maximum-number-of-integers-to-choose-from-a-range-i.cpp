class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool>v(n+1,0);
        for(int x:banned){
            if(x<=n) v[x]=1;
        }
        int c=0;
        int sum=0;
         for(int i=1;i<n+1;i++)
         {

            if(!v[i]) {sum+=i;
            if(sum<=maxSum) c++;
            else break;
            }
            
        }

        return c;

  


        
    }
};