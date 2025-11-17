class Solution {
public:
    long long countDistinct(long long n) {
        long long ans=0;

    string s=to_string(n);
    long long  m=1;
    for(int i=1;i<s.size();i++){
        m*=9;
        ans+=m;
      
    }
    for(int i=0;i<s.size()-1;i++){
     int z = s[i] - '0';

        if (z==0){
            return ans;
             break;
        }
        ans+=(z-1)*m;
        m/=9;
    }
    ans+=((s[s.size()-1])-'0');

    return ans;
    
        
    }
};