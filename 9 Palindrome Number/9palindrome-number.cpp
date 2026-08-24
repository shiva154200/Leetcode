class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int n=s.size();
        int i=0;
        int j=n-1;
        bool f=true;
        while(i<=j){
            if(s[i]!=s[j]){
                f=false;
                break;
            }
            else{i++;j--;}
        }
        return f;
        
    }
};