class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> minPQ;
       for(int n:nums){
        if(minPQ.size()<k) minPQ.push(n);
       else if (n > minPQ.top()) {
                minPQ.pop();
                minPQ.push(n);
            }
       }

       return minPQ.top();
        
    }
};