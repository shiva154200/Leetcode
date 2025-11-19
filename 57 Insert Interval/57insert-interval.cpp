class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {

        v.push_back(newInterval);
         int n=v.size();
        sort(v.begin(),v.end());

        vector<vector<int>>ans;
        ans.push_back(v[0]);
        int k=0;
        for(int i=1;i<n;i++){
            if(v[i][0]>=ans[k][0]&&v[i][0]<=ans[k][1]){
                ans[k][1]=max(ans[k][1],v[i][1]);
            }
            else{
                ans.push_back(v[i]); 
                k++;
            }
        }

        return ans;
        
    }
};