class Solution {
public: 
    vector<string>ans;
    bool isvalidip(string &t){
        if(t.size() > 1 && t[0] == '0')return false;
        int k=t.size()-1;
        int z=0;
        int m=1;
        while(k>=0){
            z+=(t[k]-48)*m;
            m*=10;
            k--;
        }
        if(z>255) return false;
        return true;
    }


    void helper(string&s,int i,int n,string ip){
       if(n==0){
        if(i==s.size()) {
            ip.pop_back();
            ans.push_back(ip);}
        else return;
       }
       if(s.size()-i>n*3||s.size()-i<n) return;
       if(n&&i>=s.size()) return ;
        int k=i;
        string t="";
        while(k<s.size()&&k<=i+2){
            t.push_back(s[k]);
            if(!isvalidip(t)) break;
            t.push_back('.');
            helper(s,k+1,n-1,ip+t);
            t.pop_back();
            k++;
        }
        return;  
       }



    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12||s.size()<4) return ans;
       string ip="";
       helper(s,0,4,ip);
       return ans;  
    }
};