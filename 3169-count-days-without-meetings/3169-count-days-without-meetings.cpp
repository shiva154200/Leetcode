class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        int ans=0;
      
        int r=0;
        for(auto & v:meetings ){
            if(v[0]>r) {ans+=(v[0]-r-1);
            r=v[1];
            }
            else r=max(r,v[1]);
            
        }

        return ans+(days-r);
        
    }
};