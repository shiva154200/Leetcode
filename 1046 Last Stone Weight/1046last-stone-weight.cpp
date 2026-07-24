class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int st:stones){
            pq.push(st);
        }
        while(pq.size()>1){
            int r=pq.top();pq.pop();
            int t=pq.top();pq.pop();
            if(r!=t) pq.push(abs(r-t));
        }
        if(pq.size()) return pq.top();
        return 0;
        
    }
};