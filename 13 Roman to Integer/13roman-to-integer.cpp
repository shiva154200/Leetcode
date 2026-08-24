class Solution {
public:
    int value(char ch){
        
        if (ch=='I') return 1;
        if (ch=='V') return 5;
        if (ch=='X') return 10;
        if (ch=='L') return 50;
        if (ch=='C') return 100;
        if (ch=='D') return 500;
        if (ch=='M') return 1000;
      return 0;
    }
    int romanToInt(string s) {
        int v=0;
        for (int i=s.length()-1;i>=0;i--){
            if(i!=s.length()-1 && (value(s[i]) < value(s[i+1]))  ) v=v-value(s[i]);
            else v=v+value(s[i]);


            }
        return v;

        }
        
        
    
};