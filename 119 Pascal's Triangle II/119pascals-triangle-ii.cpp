class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int m=rowIndex+1;
        vector<int>v(m);
        v[0]=1;
        long long prev = 1; 
        for(int i=1;i<m;i++){ 
            prev=prev*(m-i)/(i);
            v[i]=prev;}
             return v;
        }
       

    };
        

