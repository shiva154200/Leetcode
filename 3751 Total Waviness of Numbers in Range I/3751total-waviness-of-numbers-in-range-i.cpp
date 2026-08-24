class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int c=0;
        
        for(int i=num1;i<=num2;i++){
            int n=i;
            string s=to_string(n);
            int sz=s.size();
            if(sz<3) continue;

            int f=0;int l=2;
            while(l<sz){
                if((s[f+1]>s[f]&&s[f+1]>s[l])||(s[f+1]<s[f]&&s[f+1]<s[l])) {c++;}
                l++;
                f++;
            }
        }
        return c;
        
    }
};