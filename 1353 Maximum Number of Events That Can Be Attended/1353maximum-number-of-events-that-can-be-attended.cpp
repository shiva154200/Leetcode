class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start time
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, i = 0, res = 0, n = events.size();
        
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty())
                day = events[i][0]; // Jump to the next available event's start day
            
            // Push all events that start on or before 'day' into the heap
            while (i < n && events[i][0] <= day)
                minHeap.push(events[i++][1]); // Push end day
            
            // Remove events that have already expired
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();
            
            if (!minHeap.empty()) {
                minHeap.pop(); // Attend the event with the earliest end day
                res++;
            }
            day++; // Move to next day
        }
        return res;
    }
};
