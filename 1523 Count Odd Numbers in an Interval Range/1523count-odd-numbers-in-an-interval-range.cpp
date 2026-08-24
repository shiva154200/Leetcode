class Solution {
public:
    int countOdds(int low, int high) {

        int ans=high-low;

        if(low%2) return (ans+2)/2;
        return (ans+1)/2;
        
    }
};