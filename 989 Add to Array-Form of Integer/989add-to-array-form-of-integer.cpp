class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        string s=to_string(k);
        int i=s.size()-1;
        int j=num.size()-1;
        vector<int>ans;
        int c=0;
        while(i>=0&&j>=0){
            int z= num[j] + (s[i]-48)+c;
            if(z>9) {
                c=1;
                ans.push_back(z%10);
                
                }
            else {ans.push_back(z);c=0;}
         
            i--;j--;

        }
    while(i>=0){
        int z = (s[i]-48) + c;
        if(z>9) {
            c=1;
            ans.push_back(0);
        }
        else{
            ans.push_back(z);
            c=0;
        }
        i--;
    }

     while(j>=0){
        int z=num[j]+c;
        if(z>9) {
            c=1;
            ans.push_back(0);
        }
        else{
            ans.push_back(z);
            c=0;
        }
        j--;
    }
    if(c) ans.push_back(1);
    cout<<'1'-48;
    

   reverse(ans.begin(), ans.end());
   return ans;

        
    }
};