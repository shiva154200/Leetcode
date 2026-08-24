class Solution {
public:
    int canBeTypedWords(string a, string b) {
        unordered_set<char>s;
        int n=b.size();
        for(int i=0;i<n;i++){
          s.insert(b[i]);
        }
        n=a.size();
        int i=0;
        int c=0;
        while(i<n){
            int k=1;
            while(i<n&&a[i]!=' '){
                if(s.count(a[i])) k=0;
                i++;
            }
            c=c+k;
            i++;

        }

        return c;
        
    }
};