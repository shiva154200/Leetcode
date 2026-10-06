class Solution {
public:
    bool can_finish(vector<vector<int>>& tasks, int x) {
        for (auto& v : tasks) {
            if (x < v[1])
                return false;
            x -= v[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
        //     if (a[1] == b[1])
        //         return a[0] < b[0];
        //     return a[1] > b[1];
        return (a[1]-a[0])>(b[1]-b[0]);
        });

        int high = 0;
        for (auto& v : tasks)
            high += v[1];
        int low=tasks[0][1];
        int mid;
        while (low <= high) {
            mid =(high + low) / 2;

            bool f = can_finish(tasks, mid);
            if (f)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};