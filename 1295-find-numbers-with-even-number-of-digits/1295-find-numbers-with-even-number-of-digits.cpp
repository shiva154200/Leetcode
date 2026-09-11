class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int c=0;
        for(int x:nums){
            if(x==100000)c++;
           else if(x>=10000) continue;
            else if(x>=1000) c++;
            else if(x>=100) continue;
            else if(x>=10) c++;
            else continue;
        }
        return c;
        
    }
};