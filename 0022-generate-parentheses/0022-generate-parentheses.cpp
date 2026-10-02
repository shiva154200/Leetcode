class Solution {
public:
void helper(int &n,int opnbrc,int closbrc,string s,vector<string>&ans){
    if(opnbrc>n||opnbrc<closbrc) return;
    
    if(opnbrc==n&&closbrc==n){
        ans.push_back(s);
        return;

    }
    if(closbrc<opnbrc) helper(n,opnbrc,closbrc+1,s+')',ans);
    helper(n,opnbrc+1,closbrc,s+'(',ans);
    

  
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n,0,0,"",ans);
        return ans;

        
    }
};