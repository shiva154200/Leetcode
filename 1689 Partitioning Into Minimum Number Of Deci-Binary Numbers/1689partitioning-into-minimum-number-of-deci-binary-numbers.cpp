class Solution {
public:
    int minPartitions(string n) {
       char ch=n[0];

       for(int i=1;i<n.size();i++){
        if(ch<n[i]) ch=n[i];

       }

        return ch-48;
    }
};