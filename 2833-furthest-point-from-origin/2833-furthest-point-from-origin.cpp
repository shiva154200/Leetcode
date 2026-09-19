class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0;
        int r=0;
        int dash=0;

        for(char &c:moves){
            if(c=='R') r++;
            else if(c=='L') l++;
            else dash++;
        }

        return dash+abs(l-r);
        
    }
};