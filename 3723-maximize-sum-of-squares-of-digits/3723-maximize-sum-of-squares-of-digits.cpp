class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";

        string ans="";
        int i=0;
        while(i<num){
            
            if(sum>=9){
                ans.push_back('9');
                sum-=9;
            }
            else if(sum>0){
                 ans+=to_string(sum);
                 sum=0;

            }
            else  ans.push_back('0');
            i++;
        }

        return ans;



        
    }
};