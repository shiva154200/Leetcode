class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n= c.size();
        int mx=0;
        for(int i=0;i<n;i++){
            if(c[i]!=c[n-1]){
                mx=max(mx,n-1-i);
            
            }
            if(c[i]!=c[0]){
                mx=max(mx,i);
                
            }
           
        }
         
           
        

      return mx;  
    }
};