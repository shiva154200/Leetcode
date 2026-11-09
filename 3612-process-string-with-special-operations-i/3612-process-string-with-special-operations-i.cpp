class Solution {
public:
    string processStr(string s) {

        string res="";
        for(char &x:s){
            if(97<=x&&x<=122){
                res.push_back(x);
            }
            else if(x=='#'){
                res+=res;
            }
            else if(x=='%'){
                reverse(res.begin(),res.end());
            }
            else if(res.size()){
                res.pop_back();
            }
        }

        return res;
        
    }
};