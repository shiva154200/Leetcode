class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();

        for(int i=0;i<n;i++){
            capacity[i]-=rocks[i];
        }
        
        sort(capacity.begin(),capacity.end());
        int c=0;
        for(int x:capacity){
            if(additionalRocks<x) break;
          additionalRocks-=x;
          c++;
        }

        return c;

    }
};