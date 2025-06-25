class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>s;
        for(string a:words){
            s.insert(a);
           
        }
        int count=0;
         for(string a:words){
            s.erase(a);

            reverse(a.begin(),a.end());
            if(s.count(a)){
              s.erase(a);
              count++;  
            }
           
        }
     return count;
    }
};