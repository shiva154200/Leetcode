class Solution {
public:
    static inline int MOD = int(1e9) + 7; 
    int maxSum(vector<int>& nums, int k) {
        int bit_arr[32] = {0};
        for(int j : nums){
            for(int i = 0;i < 32;i++){
                if((j & (1 << i))){
                    bit_arr[i]++;
                }
            }
        }
        int res = 0;
        while(k-- > 0){
            int t = 0;
            for(int i = 0;i < 32;i++){
                if(bit_arr[i]){
                    t += (1 << i);
                    bit_arr[i]--;
                }
            }
            res = (res + t * 1LL * t) % MOD;
        }
        return res;
    }
};
auto it = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'a';
}();