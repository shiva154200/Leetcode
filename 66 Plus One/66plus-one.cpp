class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        while(i>=0&&digits[i]==9) i--;
        if(i<0){
            digits.push_back(0);
            digits[0]=1;
            for(int k=1;k<n;k++) digits[k]=0;

        }
        else{
            digits[i]+=1;
            
            for(int k=i+1;k<n;k++) digits[k]=0;
        }

        return digits;


    
        
    }
};