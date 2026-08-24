class Solution {
public:
    bool ispalindrome(string s){
        int j=s.size()-1;
        int i=0;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;

    }

    void helper(vector<vector<string>>&s1,vector<vector<string>>s2,string s){
        
        for( vector<string>x:s2){
            x.push_back(s);
            s1.push_back(x);
        }
    }


    vector<vector<string>> partition(string s) {
        int n =s.size();

        unordered_map<int,  vector<vector<string>> >mp;

        int i=1;

         mp[0]={{  string(1,s[0])   }};

         while(i<n){

            vector<vector<string>>t;

            if(ispalindrome(s.substr(0,i+1))){
                t.push_back({s.substr(0,i+1)});

            }
            int j=1;
            while(j<=i){
                if(ispalindrome(s.substr(j,i-j+1))){

                    helper( t,mp[j-1],s.substr(j,i-j+1)) ;
                    
                }
                j++;
            }

            mp[i]=t;
            i++;


         }


         return mp[n-1];
         



        


        
    }
};