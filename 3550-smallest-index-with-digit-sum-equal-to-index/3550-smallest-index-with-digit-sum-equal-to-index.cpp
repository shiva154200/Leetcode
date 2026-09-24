class Solution {
public:
int digitsum(int n){
    int s=0;
    while(n){
        s+=(n%10);
        n/=10;
    }
    return s;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<28&&i<nums.size();i++){
            if(digitsum(nums[i])==i) return i;
        }
        return -1;
        
    }
};