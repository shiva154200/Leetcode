class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1){
            if(st.count(n)) return false;
            st.insert(n);
            int c=0;
            while(n){
                c+=pow(n%10,2);
                n/=10;
            }
            n=c;
        }
        return true;
    }
};