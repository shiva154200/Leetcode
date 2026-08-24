class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mp=0;
        int m=prices[n-1];
        for(int i=n-1;i>=0;i--){
            int p=m-prices[i];
            if(p>mp) mp=p;
            if(prices[i]>m) m=prices[i];
        }
      return mp;  
    }
};