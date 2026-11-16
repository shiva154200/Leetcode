class Solution {
public:
  
    string digitSum(string s, int k) {

        if(s.size()<=k) return s;

        string t="";
        int i=0;
        string grp="0";
        while(i<s.size()){

            grp=s.substr(i,k);
            int sm=0;
            for(char &c:grp)
            { 
                sm+=(c-48);
            }
            t+=(to_string(sm));

            i+=k;


        }

        return digitSum(t,k);

       

      
        
    }
};