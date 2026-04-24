class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int l=0;
        int r=0;
        int d=0;

        for(int i=0;i<n;i++){
            if(moves[i]=='L')l++;
            else if(moves[i]=='R')r++;
            else d++;
        }

        return max(l,r)+d-min(l,r);
        
    }
};