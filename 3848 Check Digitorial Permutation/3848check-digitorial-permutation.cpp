class Solution {
public:
    bool isDigitorialPermutation(int n) {
        unordered_map<int ,int>fact;
        fact[0]=1;
        int m=1;
        
        for(int i=1;i<10;i++){
            m=m*i;
            fact[i]=m;
        }
        int z=n;
        long long s=0;
        unordered_map<int ,int>digits;
            
        
        while(n){
            int k=n%10;
            digits[k]++;
            s+=fact[k];
            n/=10;  
        }

        while(s){
            int k=s%10;
            if(digits.count(k)){
                digits[k]--;
                if(digits[k]==0) digits.erase(k);
            }
            else return false;
            s/=10;
        }
        return (digits.size())?false:true;
     
        
    }
};