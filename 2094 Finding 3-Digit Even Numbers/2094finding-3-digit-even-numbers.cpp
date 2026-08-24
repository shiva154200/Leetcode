class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>v;
      unordered_map<int,int>mp;
      for(int ele:digits){
        mp[ele]++;
      }

      for(int i=100;i<=998;i+=2){
        int x=i;
        int a=x%10;
        x/=10;
         int b=x%10;
        x/=10;
        int c=x;

        if(mp.count(a)){
            mp[a]--;
            if(mp[a]==0) mp.erase(a);
            if(mp.count(b)){
                 mp[b]--;
            if(mp[b]==0) mp.erase(b);
            if(mp.count(c)) v.push_back(i);
            mp[b]++;
            }
             mp[a]++;
        }
        
      }

      return v;
    }
};