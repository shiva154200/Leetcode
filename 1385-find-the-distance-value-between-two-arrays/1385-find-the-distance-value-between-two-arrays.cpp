class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
     {
        unordered_set<int>st;
        for(int &x:arr2){
            st.insert(x);
        }
        int ans=0;
        for(int x:arr1){
            bool f=true;
            for(int i=x-d;i<=x+d;i++){
                if(st.count(i)){ f=false;break;}
            }
            if(f) ans++;
        }

        return ans;
        
    }
};