class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
       priority_queue<p,vector<p>,greater<p>>Min;
       int mx=INT_MIN;
       for(int i=0;i<n;i++){

        p s{nums[i][0],{i,0}};
        Min.push(s);
        if(mx<nums[i][0]) mx=nums[i][0];
       }

       vector<int>ans(2);
       ans[0]=Min.top().first;
       ans[1]=mx;

     int i,j;
       while(1){
        p cur=Min.top();Min.pop();
        i=cur.second.first;
        j=cur.second.second;
        if(nums[i].size()==j+1) break;
        p t{nums[i][j+1],{i,j+1}};

        if(mx<nums[i][j+1]) mx=nums[i][j+1];
        Min.push(t);
        cur=Min.top();
        if((mx-cur.first)==ans[1]-ans[0]){
            if(ans[0]>cur.first){
                ans[0]=cur.first;
                ans[1]=mx;
            }
            
        }
        else if((mx-cur.first)<ans[1]-ans[0]){
            ans[0]=cur.first;
                ans[1]=mx;
        }
       

       }

       return ans;
       
    }
};