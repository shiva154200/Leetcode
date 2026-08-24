class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>oc;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==c) oc.push_back(i);
        }
        int m=oc.size();

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int j;
            for (j=0;j<m;j++){
                if(oc[j]==i){
                    ans[i]=0;
                    break;   
                }
                if(oc[j]>i){
                    if(j==0){
                    ans[i]=oc[j]-i;
                    
                    
                    }
                    else{
                        int r=min(abs(i-oc[j-1]),abs(i-oc[j]));
                        ans[i]=r;
                    }
                    break;
                }
                
            }
            if (j==m) ans[i]=i-oc[m-1];
        }
        return ans;
    }
};