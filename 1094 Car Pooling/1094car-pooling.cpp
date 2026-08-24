class Solution {
public:
  
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int>mp;
        int n=trips.size();
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
});

        for(int i=0;i<n;i++){
            int np=trips[i][0];
            int frm=trips[i][1];
            int to=trips[i][2];
            for(auto &p:mp){
                if (p.first<=frm) {
                    capacity+=p.second;
                    p.second=0;
                }
            }
            if(np>capacity) return false;
            mp[to]+=np;
            capacity-=np;
        }
        return true;
    }
};