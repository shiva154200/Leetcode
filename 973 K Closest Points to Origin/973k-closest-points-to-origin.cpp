class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n=points.size();
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            int d=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({d,i});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};