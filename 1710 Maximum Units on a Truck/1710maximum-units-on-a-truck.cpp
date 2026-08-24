class Solution {
public:
    typedef pair<int,int>p;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        priority_queue<p>pq;
        for(int i=0;i<n;i++){
            p r{boxTypes[i][1],boxTypes[i][0]};
            pq.push(r);
        }

        int result=0;
        while(pq.size()){
            if(truckSize==0) break;
            p cur=pq.top();pq.pop();

            if(truckSize>=cur.second){
                truckSize-=cur.second;
                result+=(cur.first*cur.second);
            }
            else{
                result+=truckSize*cur.first;
                break;
            }
        }

    return result;
        
    }
};