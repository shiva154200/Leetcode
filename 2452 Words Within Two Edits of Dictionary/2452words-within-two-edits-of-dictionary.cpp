class Solution {
public:
bool helper(string &s1,string &s2){
    int k=0;
    int i=0;
    int n=s1.size();
    while(i<n){
        if(s1[i]!=s2[i]) k++;
        if(k>2) return false;
        i++;
    }
    return true;
}
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n=queries.size();
        int m=dictionary.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper(queries[i],dictionary[j])) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
return ans;
        
    }
};