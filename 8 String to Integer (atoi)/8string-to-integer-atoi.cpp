class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();

        while(i<n&&s[i]==' ')
        {
        i++;
        }
        if(i==n) return 0;
        int  f=1;
        if(s[i]=='-'||s[i]=='+'){
         if(s[i]=='-')   f=-1;
            i++;

        }
        while(i<n&&s[i]=='0')
        {
        i++;
        }
        if(i==n) return 0;
        long long  ans=0;
       

         while(i<n&&s[i]>=48&&s[i]<=57)
         {
           ans=ans*10+(s[i]-48);
           if(ans>=INT_MAX) break;
           
           i++;
        }
       if(ans>INT_MAX) {
        if(f==-1) return -1-INT_MAX;
        else return INT_MAX;
       }
        return f*ans;
        





        
    }
};