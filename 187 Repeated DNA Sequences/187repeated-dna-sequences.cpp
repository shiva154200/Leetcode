class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {


        int n=s.size();
        vector<string>v;
        
        unordered_map< string ,int>mp;
        string temp="";

        for(int i=0;i<10;i++){
            temp.push_back(s[i]);
            
        }

        mp[temp]++;
     
        
        

        for(int i=10;i<n;i++){

            temp=temp.substr(1);
             temp.push_back(s[i]);

             if(mp.count(temp)&& mp[temp]<2){
                v.push_back(temp);
                
             }
             mp[temp]++;


        }
        
        

        return v;
        
    }
};