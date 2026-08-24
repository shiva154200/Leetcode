class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        string s="";
        int ct=0;
        char ch=chars[0];
        for(int i=0;i<n;i++){
            if(chars[i]==ch) ct++;
            else{
                s.push_back(ch);
                if(ct>1) s+=to_string(ct);
                ct=1;
                ch=chars[i];
            }
        }
          s.push_back(ch);
          if(ct>1) s+=to_string(ct);

          for(int i=0;i<s.size();i++){
            chars[i]=s[i];
          }
          
          return s.length();


    }
};