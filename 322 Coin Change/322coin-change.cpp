class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mp(amount+1, amount+1);
        mp[0] = 0;
        int n = 1;
        while (n <= amount) {
          
                for (int i = 0; i < coins.size(); i++) {
                   if(n-coins[i]>=0){
                     mp[n]=min(mp[n],mp[n-coins[i]]+1);
                   }
                }
            n++;
        }
        if(mp[amount]>amount) return -1;
        return mp[amount];
    }
};