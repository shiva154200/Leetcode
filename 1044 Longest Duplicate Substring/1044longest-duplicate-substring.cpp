class Solution {
public:

    string s;

    bool check(int len, int &start) {

        int n = s.size();

        long long base = 26;
        long long mod = 1e9 + 7;

        long long hash = 0;
        long long power = 1;


      
        for(int i=0;i<len;i++) {

            hash = (hash * base + (s[i]-'a')) % mod;

            if(i != len-1)
                power = (power * base) % mod;
        }


        unordered_map<long long, vector<int>> mp;

        mp[hash].push_back(0);


        // rolling hash
        for(int i=len;i<n;i++) {


            // remove first character
            hash = (hash - 
                   (s[i-len]-'a') * power % mod + mod) % mod;


            // add new character
            hash = (hash * base + (s[i]-'a')) % mod;


            int idx = i-len+1;


            if(mp.count(hash)) {

                // avoid collision
                for(int j: mp[hash]) {

                    if(s.substr(j,len)==s.substr(idx,len)) {

                        start = idx;
                        return true;
                    }
                }
            }

            mp[hash].push_back(idx);
        }


        return false;
    }


    string longestDupSubstring(string str) {

        s=str;

        int n=s.size();

        int low=1;
        int high=n-1;

        int ansStart=-1;
        int ansLen=0;


        while(low<=high) {

            int mid=(low+high)/2;

            int start=-1;


            if(check(mid,start)) {

               
                ansLen=mid;
                ansStart=start;

                low=mid+1;
            }
            else {

                high=mid-1;
            }
        }


        if(ansStart==-1)
            return "";


        return s.substr(ansStart,ansLen);
    }
};