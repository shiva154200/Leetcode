class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0;
        int ans=0;

        for(char &c:s){
            if(c=='(') op++;
            else if(op) op--;
            else ans+=1;
        }

        return ans+op;
        
    }
};