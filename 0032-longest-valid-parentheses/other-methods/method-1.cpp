class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n==0) return 0;

        vector<int> prefix(n, 0);
        if (s[0] == '(')
            prefix[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '(')
                prefix[i] = prefix[i - 1] + 1;
        }

        vector<int> sufix(n, 0);
        if (s[n - 1] == ')')
            sufix[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == ')')
                sufix[i] = sufix[i + 1] + 1;
        }

        vector<pair<int,int>> ans;
        int i = 0;
        while (i < n - 1) {
            if (prefix[i] && sufix[i + 1]) {
                int j = i;
                int k = i + 1;
                while (j >= 0 && k < n ) {
                    if(prefix[j] && sufix[k]){
                         j--;
                         k++;
                    }
                    else if(ans.size()&&ans.back().second==j){
                        j=ans.back().first-1;
                        ans.pop_back();
                    }
                    else{
                        break;
                    }
                   
                }
                ans.push_back({j + 1, k - 1});
                i = k;
            } else {
                i++;
            }
        }

        int r=0;
        int mxans=0;
        int pvi=-2;
        for(const auto & p:ans){
            if(p.first==pvi+1){
                r+=(p.second-p.first+1);

            }
            else{
                mxans=max(mxans,r);
                r=(p.second-p.first+1);
            }
            pvi=p.second;
        }

         mxans=max(mxans,r);

         return mxans;


    }
};