class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        int i=0;
        while(i<n){
            if(v[i]>n||v[i]==i+1||v[i]<=0||v[v[i]-1]==v[i]) i++;
            else swap(v[i],v[v[i]-1]);
        }
        
        i=0;
        while(v[i]==i+1){
            if(i==n-1) return i+2;
            i++;
        }
        return i+1;

        
    }
};