class Solution {
public:
char higher(char ch){
        if(ch=='a') return 'c';
        else if(ch=='b') return 'c';
        else return 'b';
    }
    char smaller(char ch){
        if(ch=='a') return 'b';
        else if(ch=='b') return 'a';
        else return 'a';
    }
    string getHappyString(int n, int k) {
        int t=pow(2,n-1);
      
        string ans="";
        if(k>3*t) return "";
       
        int l;int h;
        if(k<=t) {
            ans.push_back('a');
            l=1;h=t;
        } 
        else if(k<=2*t) {
            ans.push_back('b');
            l=t+1;
            h=2*t;
        }
        else {
            ans.push_back('c');
            l=2*t+1;
            h=3*t;
        }

        while(l!=h){
            int m=(l+h)/2;

            if(m>=k) {
                h=m;
                ans.push_back(smaller(ans[ans.size()-1]));   
            }

            else{
                l=m+1;
                ans.push_back(higher(ans[ans.size()-1]));   
            }
        }

        return ans;

        
    }
};