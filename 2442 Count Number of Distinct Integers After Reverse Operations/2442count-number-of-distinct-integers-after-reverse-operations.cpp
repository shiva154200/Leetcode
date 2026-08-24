class Solution {
public:
   int reversenumber(int k){
    int r=0;
    while(k>0){
        r=r*10+(k%10);
        k/=10;
    }
    return r;
   }
    int countDistinctIntegers(vector<int>& nums) {
       unordered_set<int>s;
       for(int x:nums) {
        s.insert(x);
        s.insert(reversenumber(x));
       }

       return s.size();
    }
};