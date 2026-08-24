class Solution {
public:
    int rob(vector<int>& v) {
        int n=v.size();
        if(n==1) return v[0];
        if(n==2) return max(v[0],v[1]);
        v[2]+=v[0];
        for(int i=3;i<n;i++){
            v[i]+=max(v[i-2],v[i-3]);
        }
     return max(v[n-1],v[n-2]);
    }
};