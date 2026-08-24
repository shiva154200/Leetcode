class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n=h.size();

        sort(h.begin(),h.end());
      int i=n-2;
       int k1=1;

    long long ans=h[n-1];

     while(k1<k){

        if(h[i]-k1<=0) return ans;
        ans+=(h[i]-k1);
        i--;
        k1++;

     }

     return ans;
        
    }
};