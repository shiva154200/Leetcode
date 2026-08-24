class Solution {
public:
    string intToRoman(int num) {
        char roman[7]={'I','V','X','L','C','D','M'};
       
        string s=to_string(num);
        int m=s.size();
        string ans="";
        int r;
        int j=0;
        if(m==4){
            int f=(int)s[0]-48;
            for(int i=0;i<f;i++)
            ans+="M";
            j=1;
            r=4;
        }

       else r=2*(m-1);
      

        while(j<m){

            char ch1=roman[r];
            char ch2=roman[r+1];
            char ch3=roman[r+2];
            int d=(int)s[j]-48;
            if(d<=3){
                for(int i=0;i<d;i++){
                    ans+=ch1;
                }   
            }
            else if(d==4){
                ans+=ch1;
                ans+=ch2;

            } 

            else if(d<=8){
                ans+=ch2;
                for(int i=0;i<(d-5);i++){
                    ans+=ch1;
                }  

            }
            else {
                ans+=ch1;
                ans+=ch3;
            }
            j++;
            r-=2;
        }
       return ans; 
        
    }

  
};