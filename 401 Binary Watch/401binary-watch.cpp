class Solution {
public:
int numberofSetBits(int n){
    int c=0;
    while(n|0){
        if(n&1) c++;
        n>>=1;
    }
    
    return c;
    
}
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>time;
        unordered_map<int,int>mp;

        for(int i=0;i<60;i++){
            mp[i]=numberofSetBits(i);
        }

        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(mp[i]+mp[j]==turnedOn){

                    string reading=to_string(i)+":";
                    if(j/10==0) reading.push_back('0');
                    reading+=to_string(j);
                time.push_back(reading);
                }
            }
        }
   return time;


        
    }
        
    
};