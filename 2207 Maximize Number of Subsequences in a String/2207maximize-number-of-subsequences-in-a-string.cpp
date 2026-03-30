class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n=text.size();
        vector<int>prefix(n);
        char p=pattern[0];
        long long c=0;
        long long ans=0;
        for(int i=0;i<n;i++){
          if(text[i]==p)c++;
          prefix[i]=c;
        }
        if (pattern[0]==pattern[1]) return (c*(c+1))/2;
          long long mx=0;
          
         long long k=c;
         c=0;
         p=pattern[1];
       
         for(int i=n-1;i>=0;i--){
            if(text[i]==p){
            c++;
            ans+=prefix[i];
            
            }


            long long r=c*prefix[i];
          
            if(r>=mx){
                    long long v=(c<prefix[i])?prefix[i]:c;
                    k=(k>v)?k:v;
            }
      
    
        }

        if(k<c) k=c;

        return ans+k;
        

        
        
    }
};