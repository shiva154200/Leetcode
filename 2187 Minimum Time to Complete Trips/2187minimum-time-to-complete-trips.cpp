class Solution {
public:
    bool isvalidtime(vector<int>& time, int totalTrips,long long Time){
        long long trips=0;
        int i=0;
        while(i<time.size()){
            trips+=Time/time[i];
            i++;
        }
        return (trips>=totalTrips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long l = time[0];
        for(int i=0;i<time.size();i++){
            if(l>time[i]) l=time[i];
        }
        long long h = totalTrips * l;
        long long result = h;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (isvalidtime(time, totalTrips, mid)) {
                result = mid;
                h = mid-1;
            }
            else l=mid+1;
        }
        return result;
    }
};