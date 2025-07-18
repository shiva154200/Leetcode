class Solution {
public:
    string convert(string s, int r) {
        int n=s.size();
        if (r==1) return s;
        vector<string >arr(r,"");
        int k=0;
        int i=0;
        while(k<n){
            while(k<n&&i<r){
                arr[i]+=s[k];
                i++;
                k++;
            }
            i-=2;
            while(k<n&&i>=0){
                arr[i]+=s[k];
                i--;
                k++;
            }
            i+=2;
        }

        string ans="";
        for(string p:arr){
            ans+=p;
        }

        return ans;
        
    }
};