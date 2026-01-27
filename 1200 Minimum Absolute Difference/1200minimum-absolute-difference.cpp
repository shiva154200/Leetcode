class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int md=INT_MAX;
        int d;
        for(int i=1;i<n;i++){
            d=abs(arr[i]-arr[i-1]);
            if(d<md) md=d;
        }

         for(int i=1;i<n;i++){
            d=abs(arr[i]-arr[i-1]);
            if(d==md) {
                ans.push_back({arr[i-1],arr[i]});
            }
        }

return ans;
        
    }
};