class Solution {
public:

    int calc1(string &s){
        int n=s.size(), ans=0;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && s[j]==s[i]) j++;
            ans=max(ans,j-i);
            i=j;
        }
        return ans;
    }

    int calc2(string &s,char a,char b){
        int n=s.size(), ans=0;

        for(int i=0;i<n;){
            while(i<n && s[i]!=a && s[i]!=b) i++;

            unordered_map<int,int> mp;
            mp[0]=i-1;

            int diff=0;

            while(i<n && (s[i]==a || s[i]==b)){
                diff += (s[i]==a ? 1 : -1);

                if(mp.count(diff))
                    ans=max(ans,i-mp[diff]);
                else
                    mp[diff]=i;

                i++;
            }
        }
        return ans;
    }

    int calc3(string &s){
        unordered_map<long long,int> mp;
        mp[0]= -1;

        int a=0,b=0,c=0, ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;

            int x=a-b;
            int y=b-c;

            long long key=((long long)x<<32) ^ y;

            if(mp.count(key))
                ans=max(ans,i-mp[key]);
            else
                mp[key]=i;
        }
        return ans;
    }

    int longestBalanced(string s) {
        return max({
            calc1(s),
            calc2(s,'a','b'),
            calc2(s,'b','c'),
            calc2(s,'a','c'),
            calc3(s)
        });
    }
};
