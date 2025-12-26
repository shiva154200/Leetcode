class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        vector<int>ans(n);
        int ct=0;

        for(int i=n-1;i>=0;i--){
            if(c[i]=='Y') ct++;
            ans[i]=ct;
        }
        ct=0;
        for(int i=0;i<n;i++){
            ans[i]+=ct;
            if(c[i]=='N') ct++;
           
        }
        int h=0;
        for(int i=0;i<n;i++){
            if(ans[i]<ans[h]) h=i; 
        }

       

        

       
        if(ans[h]==ans[n-1]&&c[n-1]=='Y'&&ans[n-1]>0) return n;
        return h;
        
        
    

        



        
    }
};