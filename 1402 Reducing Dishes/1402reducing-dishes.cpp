class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        if(v[n-1]<=0) return 0;

        int ans=0;
        int i=n-1;
        while(i>=0){
            int m=1;
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=m*v[j];
                m++;
                
            }
            if (sum>ans) ans=sum;
            i--;
        }
        return ans;

        
    }
};